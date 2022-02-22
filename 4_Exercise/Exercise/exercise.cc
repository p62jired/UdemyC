#include <algorithm>
#include <iostream>
#include <vector>

#include "exercise.h"

// Exercise 2
std::vector<double> max_row_values(Matrix &matrix)
{
    std::vector<double> row_max_vec(matrix.size(), 0.0);

    for (std::size_t i = 0; i != matrix.size(); i++)
    {
        auto max_row = matrix[i][0] = 0.0;
        for (std::size_t j = 0; j != matrix[i].size(); j++)
        {
            if (matrix[i][j] > max_row)
            {
                max_row = matrix[i][j];
            }
        }
        // std::cout << "Maximum of row " << i << " = " << row_max_vec[i] << std::endl;
        row_max_vec[i] = max_row;
    }
    return row_max_vec;
}

// Exercise 3
double sort_and_max(std::vector<double> &vec)
{
    std::sort(vec.begin(), vec.end());
    return vec.back();
}
