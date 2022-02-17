#pragma once
#include <cstddef>

/**
 * @brief DynamicArray Struct.
 *
 * @param double* m_data
 * @param std::size_t m_length
 */
struct DynamicArray
{
    double *m_data;
    std::size_t m_length;
};

/**
 * @brief Create a dynamic array object
 *
 * @param value The fill value for the array.
 * @param lenght  The length of array.
 * @return Dynamic array.
 */
DynamicArray create_dynamic_array(const double &value, const std::size_t &lenght);

/**
 * @brief Push backs the *value* at the end of the array.
 *
 * @param dynamic_array Dynamic array.
 * @param value The value append to the array.
 */
void push_back(DynamicArray &dynamic_array, const int &value);

/**
 * @brief Pop backs the value at the end of the array.
 *
 * @param dynamic_array Dynamic array.
 */
void pop_back(DynamicArray &dynamic_array);
