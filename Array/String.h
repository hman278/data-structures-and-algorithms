#pragma once

#include <ostream>

class String {
private:
    char* string;

public:
    String();
    String(const char* str);
    ~String();

    char GetCharAt(int index);

    String& operator=(const String& str);
    friend std::ostream& operator<<(std::ostream& os, const String& str);
};

