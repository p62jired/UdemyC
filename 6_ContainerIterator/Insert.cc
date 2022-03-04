#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <vector>

int main()
{
    std::vector<int> my_vector(5, 0);
    std::iota(my_vector.begin(), my_vector.end(), 0);

    std::vector<int> my_vector2(5, 0);
    std::iota(my_vector2.begin(), my_vector2.end(), 5);

    std::vector<int> my_vector3;

    // Inserter (Container needs the insert method)
    std::copy(my_vector.begin(), my_vector.end(), std::inserter(my_vector3, my_vector3.end()));
    std::copy(my_vector2.begin(), my_vector2.end(), std::inserter(my_vector3, my_vector3.begin()));
    std::cout << "Inserter: " << std::endl;
    for (const auto &val : my_vector3)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;
    // Back inserter (Container needs the push_back method)
    std::vector<int> my_vector4;
    std::copy(my_vector.begin(), my_vector.end(), std::back_inserter(my_vector4));
    std::copy(my_vector2.begin(), my_vector2.end(), std::back_inserter(my_vector4));
    std::cout << "Back_Inserter: " << std::endl;
    for (const auto &val : my_vector4)
    {
        std::cout << val << std::endl;
    }
    std::cout << std::endl;


    // Front inserter (Container needs the front_back method)
    // std::vector<int> my_vector5;
    // std::copy(my_vector.begin(), my_vector.end(), std::front_inserter(my_vector5));
    // std::copy(my_vector2.begin(), my_vector2.end(), std::front_inserter(my_vector5));
    // std::cout << "Front_Inserter: " << std::endl;
    // for (const auto &val : my_vector5)
    // {
    //     std::cout << val << std::endl;
    // }
    return 0;
}
