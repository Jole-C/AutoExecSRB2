#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>

namespace filesystem = std::filesystem;

int main()
{
    std::ofstream output("autoexec.cfg");
    std::string path = filesystem::current_path().string();

    if (output.is_open())
    {
        for (auto file : filesystem::directory_iterator(path))
        {
            std::filesystem::path filename = file.path().filename().string();

            if (file.is_regular_file() && filename != "autoexec.cfg")
            {
                output << "addfile " << filename << std::endl;
                std::cout << "Found file: " << filename << std::endl;
            }
        }

        std::cout << "Finished!" << std::endl;
    }
    else
    {
        std::cout << "Could not open file." << std::endl;
    }

    return 0;
}