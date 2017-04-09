#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

typedef size_t size_type;

template<class Type>
class Matrix {

public:

    Matrix() = default;
    Matrix(const size_type init_rows, const size_type init_columns);
    Matrix(const Type** init_data, const size_type init_rows, const size_type init_columns);

    Matrix(const Matrix& other);
    void operator =(const Matrix& other);
    Matrix(Matrix&& other);
    Matrix(Type**&& init_data, const size_type init_rows, const size_type init_columns);

    //getters
    const size_type get_rows() const;
    const size_type get_columns() const;
    Type at(const size_type row_index, const size_type column_index) const;

    //setters
    void set(Type& value, const size_type row_index, const size_type column_index);


    //matrix operations
    void transposition();
    Matrix transposition();
    void add(const Matrix& other);
    void operator +(const Matrix& other);

    void multiply(const Matrix& other);
    void operator *(const Matrix& other);

private:

    Type** data;
    size_type rows;
    size_type columns;
};


#endif // MATRIX_H
