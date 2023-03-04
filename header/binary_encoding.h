#pragma once
#include "../header/log.h"
#include <string>
#include <math.h> 
#include "../header/input.h"

class BinaryEncoding
{
public:
    static std::string ConvertToBinary(std::string);
private:
    static std::string get_binary(int,bool);
};