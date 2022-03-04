#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
namespace cppmath
{


template <typename T>
class Matrix
{
public:
    using MatrixDataType = std::vector<std::vector<T>>;
    Matrix() = delete;
    Matrix(std::size_t rows, std::size_t cols);
    Matrix(std::size_t rows, std::size_t cols, const T &value);

    Matrix operator+(const Matrix &rhs);
    Matrix &operator+=(const Matrix &rhs);
    Matrix operator-(const Matrix &rhs);
    Matrix &operator-=(const Matrix &rhs);
    Matrix operator*(const double &scalar);
    // Matrix &operator*=(const double &scalar);
    // Matrix operator/(const double &scalar);
    // Matrix &operator/=(const double &scalar);
    // Matrix operator*(const Matrix &rhs);
    // Matrix &operator*=(const Matrix &rhs);

    void print_matrix() const;

    std::size_t num_rows() const;
    std::size_t num_cols() const;

private:
    std::size_t m_rows;
    std::size_t m_cols;
    MatrixDataType m_data;
}; // namespace Matrix

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols)
    : m_rows(rows), m_cols(cols), m_data(m_rows, std::vector<T>(m_cols, 0))
{
}

template <typename T>
Matrix<T>::Matrix(std::size_t rows, std::size_t cols, const T &value)
    : m_rows(rows), m_cols(cols), m_data(m_rows, std::vector<T>(m_cols, value))
{
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &rhs)
{
    Matrix<T> result(m_rows, m_cols);
    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       result.m_data[i].begin(),
                       std::plus<T>());
    }
    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &rhs)
{
    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), rhs.m_data[i].begin(), m_data[i].begin(), std::plus<T>());
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs)
{
    Matrix<T> result(m_rows, m_cols);
    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(),
                       m_data[i].end(),
                       rhs.m_data[i].begin(),
                       result.m_data[i].begin(),
                       std::minus<T>());
    }
    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &rhs)
{

    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), rhs.m_data[i].begin(), m_data[i].begin(), std::minus<T>());
    }
    return *this;
}

// template <typename T>
// Matrix<T> Matrix<T>::operator*(const double &scalar)
// {
//     Matrix<T> result(m_rows, m_cols);


//     return result;
// }

// template <typename T>
// Matrix<T> &Matrix<T>::operator*=(const double &scalar)
// {


//     return *this;
// }


// template <typename T>
// Matrix<T> Matrix<T>::operator/(const double &scalar)
// {
//     Matrix<T> result(m_rows, m_cols);


//     return result;
// }

// template <typename T>
// Matrix<T> &Matrix<T>::operator/=(const double &scalar)
// {


//     return *this;
// }

// template <typename T>
// Matrix<T> Matrix<T>::operator*(const Matrix &rhs)
// {
//     Matrix<T> result(m_rows, m_cols);

//     return result;
// }

// template <typename T>
// Matrix<T> &Matrix<T>::operator*=(const Matrix &rhs)
// {

//     return *this;
// }

template <typename T>
void Matrix<T>::print_matrix() const
{
    for (std::size_t i = 0; i < m_rows; i++)
    {
        for (std::size_t j = 0; j < m_cols; j++)
        {
            std::cout << m_data[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}
template <typename T>
std::size_t Matrix<T>::num_rows() const
{
    return m_rows;
}

template <typename T>
std::size_t Matrix<T>::num_cols() const
{
    return m_cols;
}
} // namespace cppmath
