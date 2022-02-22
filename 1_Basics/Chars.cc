#include <iostream>
//https://de.wikipedia.org/wiki/American_Standard_Code_for_Information_Interchange
//https://www.ibm.com/docs/en/zos/2.3.0?topic=environments-ilp32-lp64-data-models-data-type-sizes
int main()
{
    char myChar1 = 'A';
    char offset = 2;

    std::cout << myChar1 + offset << std::endl;
    std::cout << sizeof(myChar1) << std::endl;
    return 0;
}
