// Copyright JODA Dev. All Rights Reserved. 

#include "../header/program.h"


/// @brief Default constructor
Program::Program()
{

};


/// @brief Initializes the program and begins its loop.
void Program::run()
{
    state = Program::STATE::UPDATE;
    std::cout << "ReadBits is a simple program which allows you to convert any text to binary code. You may do so by reading contents from a file or by entering text you wish to convert." << std::endl;
    loop();
};


/// @brief The programs main loop. Runs as long as STATE is not equal to EXIT.
void Program::loop()
{
    int selection = -1;
    std::string fileName ="";
    std::string binaryCode = "";

    while(state != Program::STATE::EXIT)
    {
        selection = Input::get_int_input("\nChoose what you would like to do(number only)\n 1. Convert contents from file\n 2. Enter contents to convert\n 3. Terminate program\n\nEnter selection:");

        switch(selection)
        {
        case 1:
            fileName = Input::get_string_input("\nWhat file would you like to convert?");
            
            binaryCode = ConvertToBinary(get_contents_from_file(fileName));

            if(binaryCode != "")
            {
                if(Input::get_boolean_input("\nSave to file?(y or n) - (no will just display binary code)"))
                {
                    FileManager::Write(fileName,binaryCode);
                }
                else
                {
                    std::cout << "Binary: " << binaryCode << std::endl;
                }
            }
            
            break;
        case 2:
            binaryCode = ConvertToBinary(Input::get_string_input("Enter what you would like to convert to binary:"));
            
            std::cout << "Binary: " <<  binaryCode << std::endl;
            break;
        case 3:
            terminate();
            return;
        default:
            std::cout << "Invalid input: terminating program.." << std::endl;
            break;
        }

        if(Input::get_boolean_input("\nTerminate program?(y or n)")) 
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


/// @brief Opens file(if it exists), get all contents, and return the data.
/// @param fileName File to open
/// @return contents (string)  
std::string Program::get_contents_from_file(std::string fileName)
{
    std::string contents = FileManager::Read(fileName);
    if(contents.size() == 0)
    {
        Log::logError("There are no contents to convert..");
        return "";
    }
    return contents;
}


/// @brief Retrieves file contents from specified file name and converts each character to binary machine code.
/// @param fileName file to convert
/// @return full binary code as string
std::string Program::ConvertToBinary(std::string contents)
{
    std::string fullBinary = "";
    for(char c : contents)
    {
        std::string binary = BinaryEncoding::get_binary(int(c));
        if(binary == "") terminate();
        fullBinary += binary;
    }
    return fullBinary;
}