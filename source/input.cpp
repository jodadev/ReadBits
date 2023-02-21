// Copyright JODA Dev. All Rights Reserved. 

#include "../header/input.h"

void Input::clear_buffer()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/// @brief Uses cin to obtain input from the user and saves it as a string.
/// @brief Optionally, the user may pass a string as argument to display a 
/// @brief message to the console before accepting input
/// @param msg Message(string) - used to display to console before taking input.
/// @return User input(string)
std::string Input::get_string_input(std::string msg)
{
    std::cout << msg << std::endl;
    std::string input;
    std::cin >> input;
    clear_buffer();
    return input;
}

/// @brief Uses cin to obtain input from the user and saves it as a string.
/// @return User input(string)
std::string Input::get_string_input()
{
    std::string input;
    std::cin >> input;
    clear_buffer();
    return input;
}

/// @brief Gets input from user and based on input will return true or false. 
/// @brief By default, a "true value" and "false value" of "y" and "n" are used in 
/// @brief condition, user may pass different values as arguments. 
/// @brief This overload requires a string argument to display a message to the 
/// @brief console before taking input.
/// @param msg Message(string) - used to display to console before taking input.
/// @return User input(boolean)
bool Input::get_boolean_input(std::string msg, std::string trueVal, std::string falseVal)
{
    while(true)
    {
        std::cout << msg << std::endl;
        std::string input = get_string_input();

        if(input == trueVal) 
        {
            return true;
        }
        else if(input == falseVal) 
        {
            return false;
        }
    }
}

/// @brief Get input in the form of integer
/// @param msg Message(string) - used to display to console before taking input.
/// @return User input(integer)
int Input::get_int_input(std::string msg)
{
    std::cout << msg << std::endl;
    std::string input;
    std::cin >> input;
    clear_buffer();
    return std::stoi(input);
}