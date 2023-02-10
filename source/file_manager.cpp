// Written by JODA Dev

#include "../header/file_manager.h"
#include "../header/binary_encoding.h"

/// @brief Attempts to open file, collect its contents and returns them to caller. If failed, returns empty string. 
/// @param fName file name(string)
/// @return Contents(string)
std::string FileManager::Read(std::string fName)
{
    std::ifstream ifs;
    ifs.open(fName+".txt", std::ios::in | std::ios::binary);

    if(ifs.is_open())
    {
        std::string contents;
        char c = ifs.get();
        while (ifs.good()) {
            contents += c;
            //std::cout << "Character: " << c << " | Binary: " << BinaryEncoding::get_binary(int(c)) << " | Decimal: " << int(c) << std::endl;
            c = ifs.get();
        }

        return contents;

        ifs.close();
    }
    else
        Log::logError("Could not open file.. make sure you've enter the file name correctly and that the file is in the same directory as the .exe file!");

    return "";
};