#ifndef MATRIX_H
#define MATRIX_H

#include "const_matrix_iterator.h"
#include "matrix_iterator.h"
#include "exceptions.h"
#include "basic_operations.h"

#include <iostream>
#include <cstring>
#include <ios>

namespace my_cont {

    typedef size_t size_type;

    template<class Type>
    class matrix
    {

        public:


            typedef matrix_iterator<Type> matrix_iterator;
            typedef const_matrix_iterator<Type> const_matrix_iterator;

            matrix() = default;
            matrix(const size_type init_rows, const size_type init_columns);
            matrix(const matrix<Type>& other);
            matrix(matrix&& other);
            matrix&  operator=(const matrix& other);
            ~matrix();

            size_type get_rows() const;
            size_type get_columns();

            matrix_iterator begin();
            const_matrix_iterator cbegin() const;

            matrix_iterator end();
            const_matrix_iterator cend() const;

            bool is_square() const;
            bool can_add(const matrix& other) const;
            bool can_multiply(const matrix& other) const;
            bool can_be_multiplied_by(const matrix& other) const;

            matrix operator+(const matrix& other) const;
            matrix& operator+=(const matrix& other);

            matrix operator-(const matrix& other) const;
            matrix& operator-=(const matrix& other);

            matrix operator*(const matrix& other) const;
            matrix operator*(const double number) const;
            matrix operator*(const int number) const;
            matrix& operator*=(const matrix& other);
            matrix& operator*=(const double number);
            matrix& operator*=(const int number);

            matrix transposition() const;
            matrix in_power_of(const unsigned number) const;

            template<class T>
            friend std::istream& operator>>(std::istream& source, matrix<T>& matr);
            void read(std::istream& source);

            template<class T>
            friend std::ostream& operator<<(std::ostream& destination, const matrix<T>& matr);

            void print(std::ostream& destination) const;

            const Type& at(const size_type row, const size_type column) const;

    private:
            Type* data;
            size_type rows;
            size_type columns;
    };
}

#include "matrix_impl.h"

#endif // MATRIX_H
