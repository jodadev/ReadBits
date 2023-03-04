#pragma once
#include "../header/file_manager.h"
#include "../header/binary_encoding.h"
#include "../header/log.h"
#include "../header/input.h"
#include <iostream>
#include <string>

/// @brief Main class for Read Bits program. Includes initialization and program loop with selections and input captures.
class Program
{
public:
    enum STATE { UPDATE, EXIT };
    Program();
private:
    STATE state;
    void loop();
    void terminate();
    std::string ConvertToBinary(std::string);
    void ConvertByFile();
    void ConvertByString();
};