#pragma once
#include <cstddef>
#include <utility>

template <typename T>
class DynamicArray
{
public:
    //Constructors/Destructor
    DynamicArray();
    DynamicArray<T>(const T &value, const std::size_t &length);
    ~DynamicArray() noexcept;
    //Data-manipulation methods
    void push_back(const T &value);
    void pop_back();

    //Copy-Constructor/Assignment Operator
    DynamicArray(const DynamicArray<T> &other);
    DynamicArray &operator=(const DynamicArray<T> &other);

    //Move-Constructor/Assignmet Operator
    DynamicArray(DynamicArray &&other) noexcept;
    DynamicArray &operator=(DynamicArray &&other) noexcept;

    //Operator overloading
    T &operator[](const std::size_t index);
    const T &operator[](const std::size_t index) const;

    //Helper methods
    //const at the end of the method tells that this method does not chage the
    std::size_t get_length() const;

private:
    //member variablen
    std::size_t m_length;
    std::size_t m_capacity;
    T *m_data;
};

/**
 * @brief Create a dynamic array object

 */
template <typename T>
DynamicArray<T>::DynamicArray() : m_length(0), m_capacity(1), m_data(new T[m_capacity])
{
}

/**
 * @brief Create a dynamic array object
 *
 * @param value The fill value for the array.
 * @param lenght  The length of array.
 * @return Dynamic array.
 */
template <typename T>
DynamicArray<T>::DynamicArray(const T &value, const std::size_t &lenght)
    : m_length(lenght), m_capacity(lenght > 0 ? lenght : 1), m_data(new double[m_capacity])
{

    for (std::size_t i = 0; i < lenght; i++)
    {
        m_data[i] = value;
    }
}

/**
 * @brief Destroys a dynamic array object
 *
 */
template <typename T>
DynamicArray<T>::~DynamicArray() noexcept
{
    if (m_data != nullptr)
    {
        delete[] m_data;
        m_data = nullptr;
    }
}
/**
 * @brief Copy constructor.
 *
 * @param other other DynamicArray
 */
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other)
    : m_length(other.m_length), m_capacity(other.m_capacity),
      m_data(other.m_length > 0 ? new T[other.m_length] : nullptr)
{
    for (std::size_t i = 0; i != m_length; i++)
    {
        m_data[i] = other.m_data[i];
    }
    std::cout << "Copy constructor - other.length = " << other.m_length << "- this.m_length = " << m_length
              << std::endl;
}
/**`
 * @brief Copy assignment operator.
 *
 * @param other DynamicArray rhs of the operator.
 * @return
 */
template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other)
{
    if (this != &other)
    {
        if (m_length != other.m_length)
        {
            delete[] m_data;

            m_length = other.m_length;
            m_capacity = other.m_capacity;

            if (other.m_length > 0)
            {
                m_data = new T[other.m_length];
            }
            else
            {
                m_data = nullptr;
            }
        }
        for (std::size_t i = 0; i != m_length; i++)
        {
            m_data[i] = other.m_data[i];
        }
    }
    std::cout << "Copy assignment operator - other.length = " << other.m_length << "- this.m_length = " << m_length
              << std::endl;
    return *this;
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray &&other) noexcept
    : m_length(std::move(other.m_length)), m_capacity(std::move(other.m_capacity)), m_data(std::move(other.m_data))
{
    other.m_length = 0;
    other.m_capacity = 0;
    other.m_data = nullptr;
    std::cout << "Move constructor - other.length = " << other.m_length << "- this.m_length = " << m_length
              << std::endl;
}

template <typename T>
DynamicArray<T> &DynamicArray<T>::operator=(DynamicArray &&other) noexcept
{
    if (this != &other)
    {
        delete[] m_data;

        m_length = std::move(other.m_length);
        m_capacity = std::move(other.m_capacity);
        m_data = std::move(other.m_data);

        other.m_length = 0;
        other.m_capacity = 0;
        other.m_data = nullptr;
    }
    std::cout << "Copy assignment operator - other.length = " << other.m_length << "- this.m_length = " << m_length
              << std::endl;
    return *this;
}

/**
 * @brief Push backs the *value* at the end of the array.
 *
 * @param dynamic_array Dynamic array.
 * @param value The value append to the array.
 */
template <typename T>
void DynamicArray<T>::push_back(const T &value)
{
    // if (m_capacity == 0)
    // {
    //     m_capacity = 1;
    // }

    if (m_length == m_capacity)
    {
        m_capacity *= 2;
        T *temp = nullptr;
        temp = new T[m_capacity];

        for (std::size_t i = 0; i < m_length; i++)
        {
            temp[i] = m_data[i];
        }

        delete[] m_data;
        m_data = temp;
    }
    m_data[m_length] = value;
    m_length++;
}
/**
 * @brief Pop backs the value at the end of the array.
 *
 * @param dynamic_array Dynamic array.
 */
template <typename T>
void DynamicArray<T>::pop_back()
{
    if (m_length > 0)
    {
        m_length--;
        if (m_length < (m_capacity / 2))
        {
            m_capacity /= 2;
            T *temp = nullptr;
            temp = new T[m_capacity];

            for (std::size_t i = 0; i < m_length; i++)
            {
                temp[i] = m_data[i];
            }

            delete[] m_data;

            m_data = temp;
        }
    }
}
template <typename T>
T &DynamicArray<T>::operator[](const std::size_t index)
{
    return m_data[index];
}

template <typename T>
const T &DynamicArray<T>::operator[](const std::size_t index) const
{
    return m_data[index];
}

template <typename T>
std::size_t DynamicArray<T>::get_length() const
{
    return m_length;
}
