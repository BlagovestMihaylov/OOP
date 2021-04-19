#include <iostream>
#include <cstring>

class String
{
private:
    char *string;
    size_t size;
    size_t capacity;
    bool compare(const String &_string);

public:
    String();
    String(size_t _size);
    String(const char *_string);
    String &operator=(const String &other);
    String(const String &other);
    ~String();

    void setString(const char *_string);
    void setSize(size_t _size);
    void setCapacity(int _capacity);
    void setLenght(size_t _lenght);

    const char *getString() const;
    int getSize() const;
    int getCapacity();

    void printString() const;

    void Add(char symbol);
    int getLenght() const;
    void insertAt(char symbol, int pos);
    void removeAt(int pos);
    void trimStart();
    void trimStart(int cnt);
    void trimEnd();
    void trimEnd(int cnt);
    String operator+(const String &_string2);
    String operator+=(const String &_string2);
    char operator[](size_t pos);
};

bool operator==(const String &_string1, const String &_string2);
bool operator!=(const String &_string1, const String &_string2);
