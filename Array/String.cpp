#include "./String.h"

#include <iostream>

int main() {
    String* string = new String("My String.");
    String* string2 = string;

    std::cout << string << std::endl;
}

String::String() {
    const char* emptyStr = "";
    this->string = const_cast<char*>(emptyStr);
}

String::String(const char* str) {
    // Avoid modifying string directly, as that will make it a non-const value
    const char* cpy = str;
    this->string = const_cast<char*>(cpy);
    std::cout << this->string << std::endl;
}

char String::GetCharAt(int index) {
    return *(this->string + sizeof(char) * index);
}

