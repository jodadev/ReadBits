#pragma once
#include <iostream>
#include <string>
class Log
{
public:
    static void logError(std::string);
    static void print(std::string, bool lineBreak = true);
};