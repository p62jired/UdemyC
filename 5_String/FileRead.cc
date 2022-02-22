#include <fstream>
#include <iostream>
#include <string>


int main()
{
    std::string str;
    std::string text;
    std::ifstream iffile;
    iffile.open("Text.txt");

    if (iffile.is_open())
    {
        while (std::getline(iffile, str))
        {
            text += str + '\n';
        }
    }
    else
    {
        std::cout << "text not found" << std::endl;
    }
    iffile.close();
    std::cout << text << std::endl;

    return 0;
}
