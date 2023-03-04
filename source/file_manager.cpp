// Copyright JODA Dev. All Rights Reserved. 
#include "../header/file_manager.h"
#include "../header/binary_encoding.h"

////////////////////////////
// METHODS
///////////////////////////

/// @brief Attempts to open file by name, collect its contents(data) and returns them to caller. 
/// @brief if failed, returns empty string. 
/// @param fName file name to open(string)
/// @return data from file(string)
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

        ifs.close();

        return contents;
    }
    else
        Log::logError("Could not open file. Make sure you've enter the file name correctly and that the .txt file is in the same directory as the .exe file!");

    return "Err";
};

/// @brief Write data to file
/// @param fName file name to save as(string)
/// @param data data to write(string)
void FileManager::Write(std::string fName, std::string data)
{
    std::ofstream ofs;
    ofs.open(fName+"_binary.txt");
    if(ofs.is_open())
    {
        ofs << data;
        ofs.close();
    }
    else
        Log::logError("Something went wrong attempting to save the file!");
}