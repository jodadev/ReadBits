// Written by JODA Dev

#include "../header/binary_encoding.h"

/// @brief Coverts decimal(UTF-8) to binary code as a byte(8 bits).
/// @param decimal UTF-8 decimal value
/// @return binary byte(string)
std::string BinaryEncoding::get_binary(int decimal)
{
    if(decimal < 0) {
        Log::logError("decimal value under 0 is not allowed!");
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

    return binaryStr;
};