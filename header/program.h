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
    void run();
private:
    STATE state;
    std::string get_contents_from_file(std::string);
    void loop();
    void terminate();
    std::string ConvertToBinary(std::string);
};