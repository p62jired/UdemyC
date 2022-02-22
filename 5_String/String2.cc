#include <fstream>
#include <iostream>
#include <string>

std::string read_text(const std::string &path)
{
    std::string str, text;

    std::ifstream iffile;
    iffile.open(path);

    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + "\n";
        }
    }
    iffile.close();

    return text;
}
void writte_text(const std::string &path, const std::string &text)
{
    std::ofstream offile;

    offile.open(path);
    if (offile.is_open())
    {
        offile << text;
    }
    offile.close();
}
int main()
{
    // einsnnzweinndrei
    std::string text = read_text("Text.txt");
    std::cout << text << std::endl;
    std::string search_str = "drei";
    auto idx = text.find(search_str);


    if (idx != std::string::npos)
    {
        std::cout << "Found!!" << std::endl;
        std::cout << idx << std::endl;
    }
    else
    {
        std::cout << "Not Found" << std::endl;
    }


    return 0;
}
