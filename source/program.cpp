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

    while (state != Program::STATE::EXIT)
    {
        // Display menu, wait for input, and store it.
        const char *menuStr =
            "\nChoose what you would like to do (Enter number only)"
            "\n 1. Convert characters to bits from file\n"
            "\n 2. Enter characters to convert to bits\n"
            "\n 3. Convert bits to characters from file\n"
            "\n 4. Enter bits to convert to characters\n"
            "\n 5. Terminate program\n"
            "\nEnter selection:";
        selection = Input::get_int_input(menuStr);

        // Process input with a switch statement
        switch (selection)
        {
        // Menu option logic
        case 1:
            // Get file name as input and pass as argument
            Convert_By_File();
            break;
        case 2:
            Convert_By_String();
            break;
        case 3:
            Convert_From_Bytes_By_File();
            break;
        case 4:
            Convert_From_Bytes_By_String();
            break;
        case 5:
            terminate();
            return;

        // Handles invalid inputs(out of menu(integer selection) range)
        default:
            Log::logError("Invalid input - option " + std::to_string(selection) + " is not a valid option!");
            break;
        }
    }
}

////////////////////////////
// MENU OPTIONS
///////////////////////////

/// @brief Gets character contents from file and converts to binary machine code. Option to save binary to file or to display it to the console.
void Program::Convert_By_File()
{
    // Get file name input from user
    std::string fileName = Input::get_string_input("\nWhat file would you like to convert?");

    // Attempt to open and retrieve contents from file. Handle errors.
    std::string contents = FileManager::Read(fileName);
    if (contents.length() == 0)
    {
        Log::logError("The file returned no contents..");
        return;
    }
    else if (contents == "Err")
    {
        return;
    }

    // Attempt to convert contents from file to binary
    std::string binaryCode = BinaryCoder::Convert_To_Binary(contents);

    // Confirm binary conversion was successful or not
    if (binaryCode.length() > 0)
    {
        // Ask user if they wish to save to file or display
        if (Input::get_boolean_input("\nSave to file? (y or n) - (n = display binary code only)"))
        {
            FileManager::Write(fileName, binaryCode);
        }
        else
        {
            Log::print("\nResult:\n" + binaryCode);
        }
    }
}

/// @brief Gets character contents as input from user and converts to binary machine code.
void Program::Convert_By_String()
{
    // Attempt to convert contents to binary
    std::string binaryCode = BinaryCoder::Convert_To_Binary(Input::get_string_input("Enter what you would like to convert to binary:"));

    // Confirm binary conversion was successful or not
    if (binaryCode.length() > 0)
    {
        Log::print("\nResult:\n" + binaryCode);
    }
}

/// @brief Gets binary contents from file and converts to a character string. Option to save binary to file or to display it to the console.
void Program::Convert_From_Bytes_By_File()
{

    // Get file name input from user
    std::string fileName = Input::get_string_input("\nWhat file would you like to convert?");

    // Attempt to open and retrieve contents from file. Handle errors.
    std::string contents = FileManager::Read(fileName);
    if (contents.length() == 0)
    {
        Log::logError("The file returned no contents..");
        return;
    }
    else if (contents == "Err")
    {
        return;
    }

    std::string characters = BinaryCoder::Convert_To_Characters(contents);

    if (characters.length() > 0)
    {
        Log::print("\nResult:\n" + characters);
    }
}

/// @brief Gets binary contents as input from user and converts to a character string.
void Program::Convert_From_Bytes_By_String()
{
    std::string characters = BinaryCoder::Convert_To_Characters(Input::get_string_input("Enter what you would like to convert to characters (enter 1s and 0s multiple of 8):"));

    if (characters.length() > 0)
    {
        Log::print("\nResult:\n" + characters);
    }
}

/// @brief Terminates the program.
void Program::terminate()
{
    state = Program::STATE::EXIT;
}
