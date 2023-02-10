#pragma once
#include "../header/file_manager.h"
#include "../header/binary_encoding.h"
#include "../header/log.h"
#include "../header/input.h"
#include <iostream>
#include <string>

class Program
{
public:
    enum STATE { UPDATE, EXIT };
    Program();
    ~Program();
    void run();
    void terminate();
private:
    STATE state;
    void loop();
    void ConvertToBinary(std::string);
};