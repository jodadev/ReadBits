#pragma once
#include "../header/file_manager.h"
#include "../header/binary_coder.h"
#include "../header/log.h"
#include "../header/input.h"
#include <iostream>
#include <string>

/// @brief Main class for Read Bits program. Includes initialization and program loop with selections and input captures.
class Program
{
public:
    enum STATE
    {
        UPDATE,
        EXIT
    };
    Program();

private:
    STATE state;
    void loop();
    void terminate();
    void Convert_By_File();
    void Convert_By_String();
    void Convert_From_Bytes_By_File();
    void Convert_From_Bytes_By_String();
};