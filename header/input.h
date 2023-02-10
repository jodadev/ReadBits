#pragma once
#include <iostream>
#include <string>

class Input
{
public:
    static bool get_boolean_input(std::string, std::string trueVal = "y", std::string falseVal = "n");
    static std::string get_string_input();
    static std::string get_string_input(std::string);
};