#include <iostream>

#include "Matrix.h"

int main()
{
    cppmath::Matrix<double> m1(2, 2, -1.0);
    m1.print_matrix();
    cppmath::Matrix<double> m2(2, 3, -1.0);
    m2.print_matrix();


    try
    {
        cppmath::Matrix<double> m3 = m1 + m2;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        cppmath::Matrix<double> m3 = m1 / 0;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;
}
