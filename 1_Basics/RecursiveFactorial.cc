#include <iostream>

unsigned long long factorial(unsigned int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
    }
    else
    {
        return 1;
    }
}

int main()
{
    unsigned int n = 60;
    unsigned long long nFac = factorial(n);

    std::cout << "n! = " << nFac << std::endl;
    return 0;
}
