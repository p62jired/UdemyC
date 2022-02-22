#include <iostream>
#include <vector>

void print_matrix(const std::vector<std::vector<int>> &matrix)
{
    for (std::size_t i = 0; i < matrix.size(); i++)
    {
        for (std::size_t j = 0; i < matrix[i].size(); j++)
        {
            std::cout << "Matrix[" << i << "," << j << "]=" << matrix[i][j] << std::endl;
        }
    }
    std::cout << std::endl;
}
int main()
{

    const std::size_t mum_rows = 3;
    const std::size_t mum_cols = 2;
    std::vector<std::vector<int>> matrix(mum_rows, std::vector<int>(mum_cols, 0));

    print_matrix(matrix);
    return 0;
}
