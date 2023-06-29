// Copyright JODA Dev. All Rights Reserved.
#include "../header/binary_coder.h"

////////////////////////////
// METHODS
///////////////////////////

/// @brief Converts decimal(UTF-8) to byte(8 bits) as a string.
/// @param decimal UTF-8 decimal value.
/// @param addSpaces true = concats a space at the end of the byte string.
/// @return binary byte(string)
std::string BinaryCoder::get_byte(int decimal, bool addSpaces)
{
    if (decimal < 0)
    {
        Log::logError("BinaryEncoding - negative numbers are not allowed!");
        return "";
    }

    std::string binaryStr = "";
    // loop through 8 bits
    for (int i = 7; i > -1; i--)
    {
        // get current bit (max) value
        int bit = pow(2, i);
        // Convert logic to add 1 or 0 to the binary string
        if (bit <= decimal)
        {
            binaryStr += "1";
            decimal = (decimal - bit);
            continue;
        }
        binaryStr += "0";
    }

    if (addSpaces)
        binaryStr += " ";

    return binaryStr;
};

std::tuple<int, int> BinaryCoder::validate_binary_length(int length)
{
    int remainder = length % 8; // check if length is in multiples of 8 (if so remainder should be 0)
    if (remainder != 0)
    {
        // if remainder exists then the input is not of multiples of 8 so we remove the strangling bits at end because a byte is 8 bits
        // we set a new cap to tell the algorithm to not consider bits after this cap by taking original length and subtracting the remainder
        length = length - remainder;
    }
    return std::make_tuple(length, remainder);
}

/// @brief Converts each character of the input string to binary machine code.
/// @param inputContent character input string to convert to binary.
/// @return full binary code as string.
std::string BinaryCoder::Convert_To_Binary(std::string inputString)
{
    std::string binaryResult = "";

    bool addSpaces = Input::get_boolean_input("Do you wish to add spaces in between each character byte? (y or n)");

    // Loop through input string
    for (char _char : inputString)
    {
        // Get character byte
        std::string byte = get_byte(int(_char), addSpaces);
        // If error occurred, set binaryResult back to "" to fail the entire task and return
        if (byte.length() <= 0)
        {
            Log::logError("BinaryEncoding - Something went wrong when attempting to convert contents to binary!");
            binaryResult = "";
            return binaryResult;
        }
        // Else, concat to the result string
        binaryResult += byte;
    }
    // return the result
    return binaryResult;
}

/// @brief Converts each 8 characters(byte) of the input string to ASCII Character string.
/// @param inputContent binary input string to convert to ASCII Character string.
/// @return full converted string.
std::string BinaryCoder::Convert_To_Characters(std::string inputString)
{
    std::string characterResult = "";

    bool addSpaces = Input::get_boolean_input("Do you wish to add spaces in between each character? (y or n)");

    /// @brief Validate that the length of input string is in multiples of 8.
    /// @return A tuple for the inputLength(may be adjusted if remainder exists) and remainder(if any)
    const auto [inputLength, remainder] = validate_binary_length(inputString.length());

    int byteBitIndex = 1; // current bit out of a byte
    int decimal = 0;      // character value as decimal in ASCII
    // Loop through input string
    for (int i = 0; i < inputLength; i++)
    {
        char character = inputString[i];

        if (character == '1' || character == '0')
        {
            if ((int(character) - 48) == 1) // ASCII '1' = 49, '0' = 48 so we type cast char to its int form and sub 48 to get remainder
            {
                switch (byteBitIndex)
                {
                case 8:
                    decimal += 1;
                    break;
                case 7:
                    decimal += 2;
                    break;
                case 6:
                    decimal += 4;
                    break;
                case 5:
                    decimal += 8;
                    break;
                case 4:
                    decimal += 16;
                    break;
                case 3:
                    decimal += 32;
                    break;
                case 2:
                    decimal += 64;
                    break;
                case 1:
                    decimal += 128;
                    break;
                }
            }

            if (byteBitIndex == 8)
            {
                // get character using the 8 bits
                std::string s(1, decimal);
                characterResult += s;
                //  reset bitCount to 1
                byteBitIndex = 1;
                decimal = 0;
            }
            else
            {
                byteBitIndex++;
            }
        }
        else
        {
            Log::logError("You've entered a binary with spaces or another invalid input, that is not allowed! Try again.");
            return "";
        }
    }

    if (remainder != 0)
    {
        Log::print("Whoops, you did not enter a binary code in multiples of 8, the last strangling bits were removed!");
    }
    return characterResult;
}