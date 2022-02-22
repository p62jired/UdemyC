#include <iostream>

//Call by value (local copy)
void f1(int num)
{
    num++;
    std::cout << "By value  = " << num << std::endl;
}
//Call by reference
void f2(int &num)
{
    num++;
    std::cout << "By reference  = " << num << std::endl;
}
int f3(int num)
{
    num++;
    return num;
}

int main()
{
    int number = 0;
    f1(number);
    f2(number);
    number = f3(number);
    std::cout << "Return = " << number << std::endl;
    return 0;
}
