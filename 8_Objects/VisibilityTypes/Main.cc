#include <iostream>

class A
{
public:
    int x; //In Base class and in derived class and  outside of any class

protected: //In Base class and in derived class, not outside of any class
    int y;

private: //Only in Base class, not in derived class, nor outer of an class
    int z;
};

class B : public A
{
    //x is public
    //y is protected
    //z is not accessible from B
    void foo()
    {
        std::cout << y << std::endl;
    }
};
class C : protected A
{
    //x is protected
    //y is protected
    //z is not accessible from C
    void foo()
    {
        std::cout << x << std::endl;
    }
};
class D : private A
{
    //x is private
    //y is private
    //z is not accessible from D
    void foo()
    {
        std::cout << x << std::endl;
    }
};
// class Derived_D : protected D
// {
//     //x is private
//     //y is private
//     //z is not accessible from D
//     void foo()
//     // {
//     //     std::cout << x << std::endl;
//     // }
// };
int main()
{
    A a;
    a.x;

    return 0;
}
