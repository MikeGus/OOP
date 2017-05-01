#ifndef MATRIX_H
#define MATRIX_H

#include "const_matrix_iterator.h"
#include "matrix_iterator.h"
#include "exceptions.h"
#include "basic_operations.h"
#include "base_matrix.h"

#include <iostream>
#include <cstring>
#include <ios>
#include <cmath>

namespace my_cont {

    typedef size_t size_type;

    template<class Type>
    class matrix: public base_matrix
    {
        class proxy
        {
            public:
                proxy(size_type init_columns, Type* init_data);

                Type& operator[](size_type column);
                const Type& operator[](size_type column) const;

            private:
                size_type col_count;
                Type* data;
        };

        public:

            typedef matrix_iterator<Type> matrix_iterator;
            typedef const_matrix_iterator<Type> const_matrix_iterator;

            explicit matrix() = default;
            explicit matrix(const size_type init_rows, const size_type init_columns);
            matrix(const matrix<Type>& other);
            explicit matrix(matrix&& other);
            matrix&  operator=(const matrix& other);
            ~matrix();

            matrix_iterator begin();
            const_matrix_iterator cbegin() const;

            matrix_iterator end();
            const_matrix_iterator cend() const;

            matrix operator+(const matrix& other) const;
            matrix& operator+=(const matrix& other);

            matrix operator-(const matrix& other) const;
            matrix& operator-=(const matrix& other);

            matrix operator*(const matrix& other) const;
            matrix operator*(const Type& number) const;
            matrix& operator*=(const matrix& other);
            matrix& operator*=(const Type& number);

            matrix transposition() const;
            matrix inverse() const;
            matrix in_power_of(const unsigned number) const;
            Type determinant() const;

            template<class T>
            friend std::istream& operator>>(std::istream& source, matrix<T>& matr);
            void read(std::istream& source);

            template<class T>
            friend std::ostream& operator<<(std::ostream& destination, const matrix<T>& matr);

            const Type& at(const size_type row, const size_type column) const;
            Type& at(const size_type row, const size_type column);

            proxy operator[](const size_type row);
            const proxy operator[](const size_type row) const;

    private:
            Type* find_column(size_type column) const;
            Type* data = nullptr;
    };
}

#include "matrix_impl.h"

#endif // MATRIX_H
