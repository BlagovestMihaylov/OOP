#include "String.h"
#include <iostream>

String::String()
{
    buffer = nullptr;
    size = 0;
}

String::String(const String &s)
{
    size = s.size;
    buffer = new char[size];
    for (int i = 0; i < size; i++)
    {
        buffer[i] = s.buffer[i];
    }
}

String::String(const char *p)
{
    int i = 0;
    const char *t = p;

    while (*p++)
    {
        i++;
    }

    buffer = new char[i];
    int j = 0;

    for (j; *t; t++, j++)
    {
        buffer[j] = *t;
    }
    size = j;
}

String::~String()
{
    delete[] buffer;
}

int String::length() const
{
    if (buffer == nullptr)
    {
        return 0;
    }
    else
    {
        return size;
    }
}

void String::setLength(size_t size)
{
    size_t old_length = this->length();
    char *old_buffer = this->buffer;

    this->size = size;
    this->buffer = new char[size];

    // Copy the characters (or add \0 if there are no characters anymore).
    for (size_t i = 0; i < size; i++)
    {
        if (i < old_length)
        {
            this->buffer[i] = old_buffer[i];
        }
        else
        {
            this->buffer[i] = '\0';
        }
    }

    // Destroy the old buffer
    delete[] old_buffer;

    // Ensure that the last element is \0
    this->buffer[size] = '\0';
}

void String::add(const String &text)
{
    size_t new_size = this->size + text.size;
    setLength(new_size);

    size_t length = this->length();
    for (size_t i = length; i < new_size; i++)
    {
        this->buffer[i] = text.buffer[i - length];
    }
}

char String::get(size_t pos) const
{
    if (pos > length())
    {
        return '\0';
    }
    return buffer[pos];
}

bool String::compare(const String &string) const
{
    return strcmp(this->buffer, string.buffer) == 0;
}

void String::printString() const
{
    for (int i = 0; i < length(); i++)
    {
        std::cout << buffer[i];
    }
    std::cout << std::endl;
}
char &String::operator[](unsigned int x)
{
    return buffer[x];
}

void String::operator=(const String &s)
{
    buffer = s.buffer;
    setLength(s.length());
}

// String String::operator+(const String &s1)
// {
//     String temp;
//     temp.add(this->buffer);
//     temp.add(s1.buffer);
//     return temp;
// }

// String String::operator+=(const String &s)
// {
//     this->add(s.buffer);
//     return *this;
// }

bool operator==(const String &s, const String &t)
{
    if (s.length() != t.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s.buffer[i] != t.buffer[i])
            {
                return false;
            }
        }
    }
    return true;
}