#include <filesystem>
#include <iostream>
#include <string>
namespace fs = std::filesystem;

int main()
{
    fs::path workspace_path = "/home/linux/Dokumente/Course/UdemyC";
    fs::path chapter_path;
    chapter_path = workspace_path;
    chapter_path /= "5_String";
    std::cout << workspace_path << std::endl;
    std::cout << chapter_path << std::endl;

    fs::path current_file_path = fs::current_path();
    current_file_path /= "FileSystem.cc";
    std::cout << "Current path: " << current_file_path << std::endl;


    std::cout << "Parent: " << current_file_path.parent_path() << std::endl;
    std::cout << "filename : " << current_file_path.filename() << std::endl;
    std::cout << "extension : " << current_file_path.extension() << std::endl;
    std::cout << "Stem: " << current_file_path.stem() << std::endl;
    return 0;
}
