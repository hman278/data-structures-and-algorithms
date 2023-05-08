#pragma once

#include <ostream>
#include <iostream> // delete later

class String {
private:
    char* string;

public:
    String();
    String(const char* str);
    ~String();

    char GetCharAt(int index);

    String& operator=(const String& str) {
        this->string = str.string;
    }

    friend std::ostream& operator<<(std::ostream& os, const String& str);
};

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << "ds";
    
    return os;
}
