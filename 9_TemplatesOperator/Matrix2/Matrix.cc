#include "Matrix.h"
#include <iostream>
//contructor
Matrix::Matrix() : m_A(0), m_B(0), m_C(0), m_D(0)
{
    std::cout << "Created a empty matrix object" << std::endl;
}
Matrix::Matrix(const double &a, const double &b, const double &c, const double &d) : m_A(a), m_B(b), m_C(c), m_D(d)
{
    std::cout << "Created a matrix object with menbers values" << std::endl;
}
Matrix Matrix::operator+(const Matrix &rhs)
{
    Matrix result;

    result.set_A(get_A() + rhs.get_A());
    result.set_B(get_B() + rhs.get_B());
    result.set_C(get_C() + rhs.get_C());
    result.set_D(get_D() + rhs.get_D());

    return result;
}
Matrix &Matrix::operator+=(const Matrix &rhs)
{

    set_A(get_A() + rhs.get_A());
    set_B(get_B() + rhs.get_B());
    set_C(get_C() + rhs.get_C());
    set_D(get_D() + rhs.get_D());

    return *this;
}
Matrix Matrix::operator-(const Matrix &rhs)
{
    Matrix result;

    result.set_A(get_A() - rhs.get_A());
    result.set_B(get_B() - rhs.get_B());
    result.set_C(get_C() - rhs.get_C());
    result.set_D(get_D() - rhs.get_D());

    return result;
}
Matrix &Matrix::operator-=(const Matrix &rhs)
{
    set_A(get_A() - rhs.get_A());
    set_B(get_B() - rhs.get_B());
    set_C(get_C() - rhs.get_C());
    set_D(get_D() - rhs.get_D());

    return *this;
}


void Matrix::print_matrix() const
{
    std::cout << m_A << ", " << m_B << std::endl;
    std::cout << m_C << ", " << m_D << std::endl;
    std::cout << std::endl;
}
double Matrix::get_A() const
{
    return m_A;
}

double Matrix::get_B() const
{
    return m_B;
}

double Matrix::get_C() const
{
    return m_C;
}

double Matrix::get_D() const
{
    return m_D;
}

void Matrix::set_A(const double &new_A)
{
    m_A = new_A;
}

void Matrix::set_B(const double &new_B)
{
    m_B = new_B;
}

void Matrix::set_C(const double &new_C)
{
    m_C = new_C;
}

void Matrix::set_D(const double &new_D)
{
    m_D = new_D;
}
