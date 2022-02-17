#include <iostream>
//int *array <=> int array[]
int array_maximum(int *array, unsigned int length)
{
    int current_max_value;

    for (unsigned short i = 0; i < length; i++)
    {
        if (i == 0)
        {
            current_max_value = array[i];
        }

        if (array[i] > current_max_value)
        {
            current_max_value = array[i];
        }
    }
    return current_max_value;
}
//by pointer of char, do not need to give the length of array
void print_name(char *name)
{
    std::cout << name << std::endl;
}
int main()
{
    unsigned int array_size = 10;

    int *p = new int[array_size];
    //Size of pointer itself in bytes
    std::cout << "Size of pointer itself = " << sizeof(p) << std::endl;
    //Size of the first array element, that pointer points to in bytes
    std::cout << "Size of he first array element, that pointer points to in bytes = " << sizeof(*p) << std::endl;
    //Heap allocation
    for (unsigned int i = 0; i < array_size; i++)
    {
        p[i] = i;
    }

    // for (unsigned int i = 0; i < array_size; i++)
    // {
    //     std::cout << "Value of pointer = " << p[i] << std::endl;
    //     std::cout << "Address in stack = " << &p[i] << std::endl;
    // }

    std::cout << "Max value in array = " << array_maximum(p, array_size) << std::endl;


    //Heap de-allocation
    delete[] p;

    int a[5] = {5, 6, 7, 8, 1};
    std::cout << "Max value in array = " << array_maximum(a, 5) << std::endl;

    char my_name[]{"Diego"};
    print_name(my_name);
    return 0;
}
