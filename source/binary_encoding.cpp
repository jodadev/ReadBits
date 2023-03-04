// Copyright JODA Dev. All Rights Reserved. 
#include "../header/binary_encoding.h"

////////////////////////////
// METHODS
///////////////////////////

/// @brief Coverts decimal(UTF-8) to binary code as a byte(8 bits).
/// @param decimal UTF-8 decimal value
/// @return binary byte(string)
std::string BinaryEncoding::get_binary(int decimal, bool addSpaces)
{
    if(decimal < 0) {
        Log::logError("BinaryEncoding - negative numbers are not allowed!");
        return "";
    }
    
    std::string binaryStr = "";
    // loop through 8 bits
    for(int i = 7; i > -1; i--)
    {
        // get current bit (max) value
        int bit = pow(2,i);
        // Convert logic to add 1 or 0 to the binary string
        if(bit <= decimal)
        {
            binaryStr += "1";
            decimal = (decimal- bit);
            continue;
        }
        binaryStr += "0";
    }

    if(addSpaces) binaryStr += " ";

    return binaryStr;
};

/// @brief Retrieves file contents from specified file name and converts each character to binary machine code.
/// @param fileName file to convert
/// @return full binary code as string
std::string BinaryEncoding::ConvertToBinary(std::string contents)
{
    std::string fullBinary = "";

    bool addSpaces = Input::get_boolean_input("Do you wish to add spaces in between each character? (y or n)");
    
    for(char c : contents)
    {
        std::string binary = get_binary(int(c), addSpaces);
        // If error occurred, set fullBinary back to "" to fail the entire task
        if(binary == "") 
        {
            fullBinary = "";
            break;
        }
        fullBinary += binary;
    }

    // Handle error logging before returning
    if(fullBinary.length() <= 0)
    {
        Log::logError("BinaryEncoding - Something went wrong when attempting to convert contents to binary!");
    }

    return fullBinary;
}