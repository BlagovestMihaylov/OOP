#include <iostream>
#include <cstring>

class String
{
    int size;
    char *buffer;

public:
    String();
    String(const String &);
    String(const char *);
    ~String();

    int length() const;
    void resize(unsigned int, char);
    void insert(unsigned int, String &);

    void setLength(size_t size);

    void add(const String &text);
    char get(size_t pos) const;
    bool compare(const String &string) const;

    void printString() const;

    char &operator[](unsigned int);
    void operator=(const String &);
    // String operator+=(const String &);
    // String operator+(const String &);

    friend bool operator==(const String &, const String &);
    friend bool operator<=(const String &, const String &);
    friend bool operator<(const String &, const String &);
};
