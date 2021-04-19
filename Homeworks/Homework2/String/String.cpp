#include "String.h"

String::String()
{
    this->string = new char[6];
    strcpy(this->string, "Empty");
    this->size = 6;
    this->capacity = 6;
}

bool String::compare(const String &_string)
{
    for (int i = 0;; i++)
    {
        if (this->string[i] != _string[i])
        {
            return this->string[i] < _string[i] ? -1 : 1;
        }

        if (this->string[i] == '\0')
        {
            return 0;
        }
    }
}

String::String(size_t _size)
{
    this->string = new char[_size + 1];
    this->size = _size;
    capacity = _size;

    if (this->string != NULL)
    {
        for (size_t i = 0; i < _size; i++)
        {
            string[i] = '\0';
        }
    }
}

String::String(const char *_string)
{
    int size = strlen(_string);
    this->size = size;
    this->string = new char[size];

    if (this.string != NULL)
    {
        strncpy(this->string, _string, size);
    }
}

String::String(const String &other)
{
    this->size = other.getLength();
    this->string = new char[this->size];

    if (this->string != NULL)
    {
        strncpy(this->string, other.string, this->size);
    }
}

String::~String();
{
    if (this->string != NULL)
    {
        delete[] this->string;
    }
}

void setString(const char *_string)
{
    delete[] this->string;

    this->size = strlen(_string);
    this->string = new char[size];

    strncpy(this->string, _string, this->size);
}

char *getString() const
{
    return this->string;
}

void setSize(size_t _size)
{
    this->size = _size;
}

int getSize() const
{
    return this->size;
}

int getLenght() const
{
    return strlen(this->string);
}

void String::setLength(size_t size)
{
    size_t old_length = this->getLength();
    char *old_string = this->string;

    this->size = size;
    this->string = new char[size];

    for (size_t i = 0; i < size; i++)
    {
        if (i < old_length)
        {
            this->string[i] = old_string[i];
        }
        else
        {
            this->string[i] = '\0';
        }
    }

    delete[] old_string;

    this->string[size] = '\0';
}

void String::Add(char symbol)
{
    this->size++;
    setLength(this->size);
    this->string[size] = symbol;
}

void String::insertAt(char symbol, int pos)
{
    this->size++;
    setLenght(size);
    for (int i = getLenght(); i > pos; i--)
    {
        this.string[i] = this->string[i - 1];
    }
    this->string[pos] = symbol;
}

void String::removeAt(int pos)
{
    for (size_t i = pos; i < getLenght(); i++)
    {
        string[i] = string[i + 1];
    }

    this->size--;
    setLength(size);
}

void String::trimStart()
{
    for (size_t i = 0; i < getLenght(); i++)
    {
        string[i] = string[i + 1];
    }

    this->size--;
    setLenght(this->size);
}

void String::trimStart(int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        trimStart();
    }
}

void String::trimEnd()
{
    for (size_t i = getLenght() - 1; i > -1; i--)
    {
        this->string[i] = this->string[i - 1];
    }

    this->size--;
    setLenght(size);
}

void String::trimEnd(int cnt)
{
    for (size_t i = 0; i < cnt; i++)
    {
        trimEnd();
    }
}

String operator+=(const String &_string)
{

    int size = _string.getLenght();
    for (int i = 0; i < size; i++)
    {
        this.string.Add(_string[i]);
    }
    return *this;
}

String operator+(const String &_string)
{
    String temp;
    temp.setLenght(this.getLenght() + _string.getLenght());
    for (int i = 0; i < this.getLenght(); i++)
    {
        temp[i] = this->string[i];
    }
    for (int i = 0; i < _string.getLenght(); i++)
    {
        temp[i + this.getLenght()] = _string[i];
    }
}

bool operator==(const String &_string1, const String &_string2)
{
    return _string1.compare(_string2);
}

char operator[](size_t pos)
{
    return this->string[pos];
}

bool operator!=(const String &_string1, const String &_string2)
{
    return !(_string1.compare(_string2));
}

void printString() const
{
    for (int i = 0; i < getLenght(); i++)
    {
        std::cout << this->string[i];
    }
}