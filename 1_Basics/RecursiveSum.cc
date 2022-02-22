#include <iostream>

unsigned int sum(unsigned int n)
{
    if (n > 0)
    {
        return n + sum(n - 1);
    }
    else
    {
        return 0;
    }
}

int main()
{
    unsigned int n = 5;
    unsigned int nFac = sum(n);

    std::cout << "sum = " << nFac << std::endl;
    return 0;
}
