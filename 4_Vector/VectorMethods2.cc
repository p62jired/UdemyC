
#include <iostream>
#include <numeric>
#include <vector>

void print_vector(std::vector<int> &vec)
{
    for (std::size_t i = 0; i < vec.size(); i++)
    {
        std::cout << "Ve[" << i << "] = " << vec[i] << std::endl;
    }
}
void print_vector_info(std::vector<int> &vec)
{

    std::cout << "Size: " << vec.size() << std::endl;
    std::cout << "Capacity: " << vec.capacity() << std::endl;
    std::cout << "Empty?: " << std::boolalpha << vec.empty() << std::endl;
}

int main()
{

    std::vector<int> my_vector(10, 5);
    std::iota(my_vector.begin(), my_vector.end(), 0);
    print_vector(my_vector);
    int first = my_vector.front();
    int first2 = my_vector[0];
    std::cout << first << first2 << std::endl;

    int last = my_vector.back();
    int last2 = my_vector[my_vector.size() - 1];
    std::cout << last << last2 << std::endl;

    int *p_array = my_vector.data();
    std::cout << *p_array << std::endl;

    std::vector<int>::iterator begin = my_vector.begin();
    std::vector<int>::iterator end = my_vector.end();

    std::cout << *begin << std::endl;
    std::cout << *end << std::endl;

    begin++;
    end--;


    std::cout << *begin << std::endl;
    std::cout << *end << std::endl;

    return 0;
}
