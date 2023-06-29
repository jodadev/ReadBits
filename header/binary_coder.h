#pragma once
#include "../header/log.h"
#include <string>
#include <math.h>
#include "../header/input.h"
#include <tuple>

class BinaryCoder
{
public:
    static std::string Convert_To_Binary(std::string);
    static std::string Convert_To_Characters(std::string);

private:
    static std::string get_byte(int, bool);
    static std::tuple<int, int> validate_binary_length(int length);
};