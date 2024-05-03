
#include <iostream>
using namespace std;

class String
{
	char* buf;
//	static int strlen(const char* s);
	static char* strdup(const char* s);
	static char* strncpy(char* dest, const char* src);
	static char* strncpy(char* dest, const char* src, int n);
	static char* strcat(char* dest, const char* src);
	static char* strncat(char* dest, const char* src, int n);
	static int strcmp(const char* left, const char* right);
	static int strncmp(const char* left, const char* right, int n);
	static void reverse_cpy(char* dest, const char* src);
	static char* strchr(char* str, char c);
	static  char* strstr(char* haystack, const char* needle);
	static const char* strstr(const char* haystack, const char* needle);

public:
		static int strlen(const char* s);

	explicit String(const char* s = "");
	String(const String& s);
	String(String&& s);

	String& operator = (String&& s);
	String& operator= (const String& s);
	char& operator [] (int index);

	size_t size();
	String reverse();

	int indexOf(const char& c);
	int indexOf(const String& s);

	bool operator == (const String& s);
	bool operator != (const String& s);
	bool operator > (const String& s);
	bool operator < (const String& s);
	bool operator <= (const String& s);
	bool operator >= (const String& s);

	String operator +(const String& s);
	String& operator += (const String& s);

	void print(ostream& out)const;
	void read(istream& in);

	~String();

private:
	bool in_bounds(int i);
};

ostream& operator << (ostream& out, const String& s);
istream& operator >> (istream& in, String& s);

