
#include "string.hpp"
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

String::String(const char* s) {
    if (s) {
        buf = strdup(s);
    }
    else {
        buf = new char[1];
        *buf = '\0';
    }
}

String::String(const String& s) {
    buf = strdup(s.buf);
}

String::String(String&& s)  {
    buf = s.buf;
    s.buf = nullptr;
}

String::~String() {
    delete[] buf;
}

String& String::operator=(const String& s) {
    if (this != &s) {
        delete[] buf;
        buf = strdup(s.buf);
    }
    return *this;
}

String& String::operator=(String&& s)  {
    if (this != &s) {
        delete[] buf;
        buf = s.buf;
        s.buf = nullptr;
    }
    return *this;
}

String String::operator+(const String& s) {
    char* new_buf = new char[strlen(buf) + strlen(s.buf) + 1];
    strcpy(new_buf, buf);
    strcat(new_buf, s.buf);
    String result(new_buf);
    delete[] new_buf;
    return result;
}

String& String::operator+=(const String& s) {
    char* new_buf = new char[strlen(buf) + strlen(s.buf) + 1];
    strcpy(new_buf, buf);
    strcat(new_buf, s.buf);
    delete[] buf;
    buf = new_buf;
    return *this;
}

char& String::operator[](int index) {
    if (!in_bounds(index))
    {

        return buf[index];
    }
    cout << "\nError: Too long";

}

bool String::in_bounds(int i) {
    return i >= 0 && i < strlen(buf);
}

size_t String::size() {
    return strlen(buf);
}

String String::reverse() {
    String rev(buf); 
    std::reverse(rev.buf, rev.buf + strlen(rev.buf));
    return rev;
}

int String::indexOf(const char& c) {
    for (int i = 0; i < strlen(buf); i++) {
        if (buf[i] == c) {
            return i;
        }
    }
    return -1;
}

int String::indexOf(const String& s) {
    for (int i = 0; i <= strlen(buf) - strlen(s.buf); i++) {
        bool found = true;
        for (int j = 0; j < strlen(s.buf); j++) {
            if (buf[i + j] != s.buf[j]) {
                found = false;
                break;
            }
        }
        if (found) {
            return i;
        }
    }
    return -1;

}

bool String::operator==(const String& s) {
    return strcmp(buf, s.buf) == 0;
}

bool String::operator!=(const String& s) {
    return !(*this == s);
}

bool String::operator>(const String& s) {
    return strcmp(buf, s.buf) > 0;
}

bool String::operator<(const String& s) {
    return strcmp(buf, s.buf) < 0;
}

bool String::operator>=(const String& s) {
    return !(*this < s);
}

bool String::operator<=(const String& s) {
    return !(*this > s);
}

ostream& operator<<(ostream& out, const String& s) {
    s.print(out);
    return out;
}

istream& operator>>(istream& in, String& s) {
    char buffer[1000];
    if (in >> buffer) {
        s = String(buffer);
    }
    return in;
}

int String::strlen(const char* s) {
    int length = 0;
    while (*s) {
        ++length;
        ++s;
    }
    return length;
}

char* String::strdup(const char* s) {
    if (!s) return nullptr;
    char* newStr = new char[std::strlen(s) + 1];
    std::strcpy(newStr, s);
    return newStr;
}

char* String::strncpy(char* dest, const char* src) 
{
    char* dest_ptr = dest;
    const char* src_ptr = src;

    while (*src_ptr) {
        *dest_ptr = *src_ptr;
        ++dest_ptr;
        ++src_ptr;
    }

    *dest_ptr = '\0';

    return dest;

}

char* String::strncpy(char* dest, const char* src, int n) {
    int i;
    for (i = 0; i < n - 1 && src[i] != '\0'; ++i) {
        dest[i] = src[i];
    }
    dest[i] = '\0'; 
    return dest;

}

char* String::strcat(char* dest, const char* src) {
    char* dest_ptr = dest;

    while (*dest_ptr) {
        ++dest_ptr;
    }

    for (; *src; ++src) {
        *dest_ptr = *src;
        ++dest_ptr;
    }

    *dest_ptr = '\0';

    return dest;
}

char* String::strncat(char* dest, const char* src, int n) {
    char* dest_ptr = dest;

    while (*dest_ptr) {
        ++dest_ptr;
    }

    for (int i = 0; *src && i < n; ++i) {
        *dest_ptr = *src;
        ++dest_ptr;
        ++src;
    }

    *dest_ptr = '\0';

    return dest;
}

int String::strcmp(const char* left, const char* right) {
    while (*left && (*left == *right)) {
        ++left;
        ++right;
    }

    if (*left < *right) {
        return -1;
    }
    else if (*left > *right) {
        return 1;
    }
    else {
        return 0;
    }
}

int String::strncmp(const char* left, const char* right, int n) {
    for (int i = 0; i < n; ++i) {
        if (left[i] != right[i]) {
            if (left[i] < right[i]) {
                return -1;
            }
            else {
                return 1;
            }
        }
        if (left[i] == '\0' || right[i] == '\0') {
            break;
        }
    }
    return 0;
}

void String::reverse_cpy(char* dest, const char* src) {
    int len = strlen(src);
    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0';
}

char* String::strchr(char* str, char c) {
    while (*str) {
        if (*str == c) {
            return str;  
        }
        ++str;
    }
    return nullptr;  
}

char* String::strstr(char* haystack, const char* needle) {
    if (!haystack || !needle || *needle == '\0') {
        return haystack;
    }

    while (*haystack) {
        char* h_ptr = haystack;
        const char* n_ptr = needle;

        while (*n_ptr && *h_ptr == *n_ptr) {
            ++h_ptr;
            ++n_ptr;
        }

        if (*n_ptr == '\0') {
            return haystack;
        }

        ++haystack;
    }

    return nullptr;
}

const char* String::strstr(const char* haystack, const char* needle) {
    if (!haystack || !needle || *needle == '\0') {
        return haystack;
    }

    while (*haystack) {
        const char* h_ptr = haystack;
        const char* n_ptr = needle;

        while (*n_ptr && *h_ptr == *n_ptr) {
            ++h_ptr;
            ++n_ptr;
        }

        if (*n_ptr == '\0') {
            return haystack;
        }

        ++haystack;
    }

    return nullptr;
}

void String::print(std::ostream& out) const {
    out << buf;
}

void String::read(std::istream& in) {
    std::string temp;
    std::getline(in, temp); 
    delete[] buf;          
    buf = new char[temp.length() + 1]; 
    std::strcpy(buf, temp.c_str());   
}
