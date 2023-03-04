// Copyright JODA Dev. All Rights Reserved. 
#include "../header/log.h"

////////////////////////////
// METHODS
///////////////////////////

/// @brief Logs error message to console marked as "Error:"
/// @param msg error message (string)
void Log::logError(std::string msg)
{
    std::cout << "\nError: " << msg << std::endl;
}

/// @brief Displays a message to the console.
/// @param msg message to display (string)
/// @param lineBreak optional - add a line break or not.
void Log::print(std::string msg, bool lineBreak)
{
    if(lineBreak)
    {
        std::cout << msg << std::endl;
    }
    else
    {
        std::cout << msg;
    }   
}