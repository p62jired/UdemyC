#pragma once
#include <algorithm>
#include <exception>
#include <iostream>
#include <stdexcept>
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
    Matrix operator*(const T &scalar);
    Matrix &operator*=(const T &scalar);
    Matrix operator/(const T &scalar);
    Matrix &operator/=(const T &scalar);
    Matrix operator*(const Matrix &rhs);
    Matrix &operator*=(const Matrix &rhs);

    void dot(const Matrix &matrixA, const Matrix &matrixB, Matrix &result);
    void parallel_dot(const Matrix &matrixA, const Matrix &matrixB, Matrix &result);

    void print_matrix() const;

    std::size_t num_rows() const;
    std::size_t num_cols() const;

private:
    std::size_t m_rows;
    std::size_t m_cols;
    MatrixDataType m_data;

public:
    const std::uint32_t NUM_THREADS = 8;
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
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!!"));
    }

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
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!!"));
    }

    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), rhs.m_data[i].begin(), m_data[i].begin(), std::plus<T>());
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(const Matrix<T> &rhs)
{
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!!"));
    }
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
    if (m_rows != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of rows are not equal!!"));
    }
    if (m_cols != rhs.m_cols)
    {
        throw(std::invalid_argument("Number of cols are not equal!!"));
    }

    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), rhs.m_data[i].begin(), m_data[i].begin(), std::minus<T>());
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const T &scalar)
{
    Matrix<T> result(m_rows, m_cols);
    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), result.m_data[i].begin(), [scalar](const T val) -> T {
            return val * scalar;
        });
    }
    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const T &scalar)
{
    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), m_data[i].begin(), [scalar](const T val) -> T {
            return val * scalar;
        });
    }

    return *this;
}

template <typename T>
void Matrix<T>::dot(const Matrix &matrixA, const Matrix &matrixB, Matrix &result)
{

    for (std::size_t i = 0; i != matrixA.m_rows; i++)
    {
        for (std::size_t k = 0; k < matrixB.m_rows; k++)
        {
            for (std::size_t j = 0; j < matrixB.m_cols; j++)
            {
                result.m_data[i][j] = result.m_data[i][j] + matrixA.m_data[i][k] * matrixB.m_data[i][j];
            }
        }
    }
}

template <typename T>
void Matrix<T>::parallel_dot(const Matrix &matrixA, const Matrix &matrixB, Matrix &result)
{
    std::size_t i = 0;
    std::size_t j = 0;
    std::size_t k = 0;

#pragma omp parallel for shared(result) private(i, j, k) num_threads(NUM_THREADS)

    for (i = 0; i != matrixA.m_rows; i++)
    {
        for (k = 0; k < matrixB.m_rows; k++)
        {
            for (j = 0; j < matrixB.m_cols; j++)
            {
                result.m_data[i][j] = result.m_data[i][j] + matrixA.m_data[i][k] * matrixB.m_data[i][j];
            }
        }
    }
}


template <typename T>
Matrix<T> Matrix<T>::operator/(const T &scalar)
{
    if (scalar == 0.0)
    {
        throw(std::overflow_error("You can not divide by 0"));
    }

    Matrix<T> result(m_rows, m_cols);
    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), result.m_data[i].begin(), [scalar](const T val) -> T {
            return val / scalar;
        });
    }

    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator/=(const T &scalar)
{
    if (scalar == 0.0)
    {
        throw(std::overflow_error("You can not divide by 0"));
    }

    for (std::size_t i = 0; i != m_rows; i++)
    {
        std::transform(m_data[i].begin(), m_data[i].end(), m_data[i].begin(), [scalar](const T val) -> T {
            return val / scalar;
        });
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &rhs)
{
    if (m_cols != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of cols M1 are not equal rows M2!!"));
    }
    Matrix<T> result(m_rows, rhs.m_cols);
    if (m_rows < 250 && m_cols < 250)
    {
        dot(*this, rhs, result);
    }
    else
    {
        parallel_dot(*this, rhs, result);
    }
    return result;
}

template <typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix &rhs)
{
    if (m_cols != rhs.m_rows)
    {
        throw(std::invalid_argument("Number of cols M1 are not equal rows M2!!"));
    }

    *this = (*this) * rhs;
    return *this;
}

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
