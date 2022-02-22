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

    std::string search_str = "eins";
    std::string replace_str = "one";

    auto idx = text.find(str);
    text.replace(idx, search_str.size(), replace_str);
    std::cout << text << std::endl;

    std::ofstream offile;
    offile.open("TextOutp.txt");
    if (offile.is_open())
    {
        offile << text;
    }
    offile.close();


    return 0;
}
