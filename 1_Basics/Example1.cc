#include <iostream>

int main()
{
    unsigned short sideLeng, perimeter, squareArea;

    std::cout << "Enter the side length of a square:  ";
    std::cin >> sideLeng;
    perimeter = sideLeng * 4;
    squareArea = sideLeng * sideLeng;
    std::cout << "Perimeter of square: " << perimeter << std::endl;
    std::cout << "Area of square: " << squareArea << std::endl;
    std::cout << "Area of square: " << sizeof(squareArea) << std::endl;
    return 0;
}
