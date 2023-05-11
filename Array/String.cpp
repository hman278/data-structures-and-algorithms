#include "./String.h"

#include <iostream>

int main() {
    String* string = new String("My String.");
    String* string2 = string;

    std::cout << &string2 << std::endl;

    delete string;
    delete string2;
}

String::String() {
    // Default constructor default empty string initialization
    const char* emptyStr = "";
    this->string = const_cast<char*>(emptyStr);
}

String::String(const char* str) {
    // Avoid modifying string directly, as that will make it a non-const value
    const char* cpy = str;
    this->string = const_cast<char*>(cpy);
}

char String::GetCharAt(int index) {
    return *(this->string + sizeof(char) * index);
}

String& String::operator=(const String& str) {
    this->string = str.string;
    
    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
    os << str.string;
    
    return os;
}
