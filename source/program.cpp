// Copyright JODA Dev. All Rights Reserved. 
#include "../header/program.h"


////////////////////////////
// CONSTRUCTOR | INITIALIZER
///////////////////////////

/// @brief Default constructor. Initializes the program and begins its loop.
Program::Program()
{
    // Update the state of the program
    state = Program::STATE::UPDATE;
    // Program notice message
    Log::print("ReadBits is a simple program which allows you to convert any text to binary code. You may do so by reading contents from a file or by entering text you wish to convert.");
    // Begin program's loop
    loop();
};


////////////////////////////
// UPDATER
///////////////////////////

/// @brief The programs main loop. Runs as long as STATE is not equal to EXIT.
void Program::loop()
{
    int selection = -1;
    
    while(state != Program::STATE::EXIT)
    {
        // Display menu, wait for input, and store it.
        selection = Input::get_int_input("\nChoose what you would like to do (Enter number only)\n 1. Convert contents from file\n 2. Enter contents to convert\n 3. Terminate program\n\nEnter selection:");

        // Process input with a switch statement
        switch(selection)
        {
        
        // Menu option logic
        case 1:
            // Get file name as input and pass as argument 
            ConvertByFile();
            break;
        case 2:
            ConvertByString();
            break;
        case 3:
            terminate();
            return;
        
        // Handles invalid inputs(out of menu(integer selection) range)
        default:
            Log::logError("Invalid input - option "+std::to_string(selection)+" is not a valid option!");
            break;
        }
    }

}


////////////////////////////
// MENU OPTIONS
///////////////////////////

/// @brief Full logic to convert by file which gets file name as input, attempts to open file, retrieve contents and converts to binary
/// @brief machine code. Option to save binary to file or to display it to the console.
void Program::ConvertByFile()
{
    // Get file name input from user
    std::string fileName = Input::get_string_input("\nWhat file would you like to convert?");

    // Attempt to open and retrieve contents from file. Handle errors.
    std::string contents = FileManager::Read(fileName);
    if(contents.length() == 0)
    {
        Log::logError("The file returned no contents..");
        return;
    }
    else if (contents == "Err")
    {
        return;
    }

    // Attempt to convert contents from file to binary 
    std::string binaryCode = BinaryEncoding::ConvertToBinary(contents);

    // Confirm binary conversion was successful or not
    if(binaryCode.length() > 0)
    {
        // Ask user if they wish to save to file or display
        if(Input::get_boolean_input("\nSave to file? (y or n) - (n = display binary code only)"))
        {
            FileManager::Write(fileName,binaryCode);
        }
        else
        {
            Log::print("Binary:\n"+binaryCode);
        }
    }
}

/// @brief Gets contents as input from user and converts to binary machine code.
void Program::ConvertByString()
{
    // Attempt to convert contents to binary 
    std::string binaryCode = BinaryEncoding::ConvertToBinary(Input::get_string_input("Enter what you would like to convert to binary:"));
    
    // Confirm binary conversion was successful or not
    if(binaryCode.length() > 0)
    {
        Log::print("Binary:\n"+binaryCode);
    }
}

/// @brief Terminates the program.
void Program::terminate()
{
    state = Program::STATE::EXIT;
}










