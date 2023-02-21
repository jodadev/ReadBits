#pragma once
#include "../header/log.h"
#include <iostream>
#include <fstream> 
#include <string>

class FileManager
{
public:
    static std::string Read(std::string);
    static void Write(std::string, std::string);
};