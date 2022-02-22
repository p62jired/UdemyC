#include <iostream>
#include <string>


int main()
{
    std::string s = "Hallo das ist ein Text";
    std::size_t index = s.find("i");
    if (index != std::string::npos)
    {
        std::cout << "Index = " << index << std::endl;
    }
    else
    {
        std::cout << "Subsring not found! = " << index << std::endl;
    }
    return 0;
}
