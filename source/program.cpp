// Written by JODA Dev

#include "../header/program.h"

Program::Program()
{

};
Program::~Program()
{

};

/// @brief Initializes the program and begins its loop.
void Program::run()
{
    state = Program::STATE::UPDATE;

    loop();
};

/// @brief The programs main loop. Runs as long as STATE is not equal to EXIT.
void Program::loop()
{
    while(state != Program::STATE::EXIT)
    {
        ConvertToBinary(Input::get_string_input("\nWhat file would you like to convert?"));

        if(Input::get_boolean_input("\nWhat file would you like to convert?")) 
        {
            terminate();
        }
    }
}

/// @brief Terminates the program.
void Program::terminate()
{
    state = Program::STATE::EXIT;
}

/// @brief Retrieves file contents from specified file name and converts each character to binary machine code.
/// @param fileName file to convert
void Program::ConvertToBinary(std::string fileName)
{
    std::string contents = FileManager::Read(fileName);
    if(contents.size() == 0)
    {
        Log::logError("There are no contents to convert..");
        return;
    }

    for(char c : contents)
    {
        std::string binary = BinaryEncoding::get_binary(int(c));
        if(binary == "") terminate();
        std::cout << binary;
    }
    std::cout << std::endl;
}