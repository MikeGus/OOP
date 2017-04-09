#include "matrix.h"

template<class Type>
Matrix<Type>::Matrix(const size_type init_rows, const size_type init_columns)
{
    try {
        data = new Type[init_rows];
        for (size_type i = 0; i < init_rows; ++i) {
            data[i] = new Type[init_columns];
        }
    }
    catch(std::bad_alloc& e) { // ???
        throw e.what();
    }
}

template<class Type>
Matrix<Type>::Matrix(const Type** init_data, const size_type init_rows, const size_type init_columns)
{
    try {
        data = new Type[init_rows];
        for (size_type i = 0; i < init_rows; ++i) {
            data[i] = new Type[init_columns];
        }

        for (size_type i = 0; i < init_rows; ++i) {
            for (size_type j = 0; j < init_columns; ++j) {
                data[i][j] = init_data[i][j];
            }
        }
    }

    catch(...) { // ???

    }
}

template<class Type>
Matrix<Type>::Matrix(const Matrix& other)
{
    try {
        data = new Type[other.rows];

        for (size_type i = 0; i < other.rows; ++i) {
            data[i] = new Type[other.columns];
        }

        for (size_type i = 0; i < other.rows; ++i) {
            for (size_type j = 0; j < other.columns; ++j) {
                data[i][j] = other.data[i][j];
            }
        }

        rows = other.rows;
        columns = other.columns;
    }

    catch(...) { // ???

    }
}

template<class Type>
void Matrix<Type>::operator =(const Matrix& other)
{
    try {
        data = new Type[other.rows];

        for (size_type i = 0; i < other.rows; ++i) {
            data[i] = new Type[other.columns];
        }

        for (size_type i = 0; i < other.rows; ++i) {
            for (size_type j = 0; j < other.columns; ++j) {
                data[i][j] = other.data[i][j];
            }
        }

        rows = other.rows;
        columns = other.columns;
    }

    catch(...) { // ???

    }
}

template<class Type>
Matrix<Type>::Matrix(Matrix&& other)
{
    data = other.data;
    rows = other.rows;
    columns = other.columns;
}

template<class Type>
Matrix<Type>::Matrix(Type**&& init_data, const size_type init_rows, const size_type init_columns)
{
    data = init_data;
    rows = init_rows;
    columns = init_columns;
}

//getters
template<class Type>
const size_type Matrix<Type>::get_rows() const
{
    return rows;
}

template<class Type>
const size_type Matrix<Type>::get_columns() const
{
    return columns;
}

template<class Type>
Type Matrix<Type>::at(const size_type row_index, const size_type column_index) const
{
    try {
        return data[row_index][column_index];
    }
    catch (...){ //????

    }
}

template<class Type>
void Matrix<Type>::set(Type& value, const size_type row_index, const size_type column_index)
{
    try {
        data[row_index][column_index] = value;
    }
    catch (...) { //???

    }
}

template<class Type>
void Matrix<Type>::transposition()
{
    for (size_type i = 0; i < rows; ++i) {
        for (size_type j = i + 1; j < columns; ++j) {
            Type temp = data[i][j];
            data[i][j] = data[j][i];
            data[j][i] = temp;
        }
    }
}

template<class Type>
Matrix Matrix<Type>::transposition()
{
    Matrix other = this;
    other.transposition();
    return other;
}

template<class Type>
void add(const Matrix& other)
{
//    if (other.columns != columns || other.rows != rows) {
//        throw ...;
//    }
    for (size_type i = 0; i < rows; ++i) {
        for (size_type j = 0; j < columns; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
}

template<class Type>
void operator +(const Matrix& other)
{
    //    if (other.columns != columns || other.rows != rows) {
    //        throw ...;
    //    }
        for (size_type i = 0; i < rows; ++i) {
            for (size_type j = 0; j < columns; ++j) {
                data[i][j] += other.data[i][j];
            }
        }
}

template<class Type>
void multiply(const Matrix& other)
{
//    if (other.columns != rows || other.rows != columns) {
//        throw ...;
//    }
}

template<class Type>
void operator *(const Matrix& other);
