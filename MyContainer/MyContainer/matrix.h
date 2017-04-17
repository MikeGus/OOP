#ifndef MATRIX_H
#define MATRIX_H

#include <cstring>
#include "const_matrix_iterator.h"
#include "matrix_iterator.h"
#include "exceptions.h"
#include "basic_operations.h"

#include <iostream>

namespace my_cont {

    typedef size_t size_type;

    template<class Type>
    class matrix
    {
        private:
            Type* data;
            size_type rows;
            size_type columns;

        public:
            matrix() = delete;
            matrix(const size_type init_rows, const size_type init_columns);
            matrix(const matrix& other);
            matrix(matrix&& other);
            matrix&  operator=(const matrix& other);
            ~matrix();

            size_type get_rows();
            size_type get_columns();

            matrix_iterator<Type> begin();
            const_matrix_iterator<Type> begin() const;

            matrix_iterator<Type> end();
            const_matrix_iterator<Type> end() const;

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

            Type& at(const size_type row, const size_type column) const;
    };


    template<class Type>
    matrix<Type>::matrix(const size_type init_rows, const size_type init_columns)
    {
        try {
            data = new Type[init_rows * init_columns];
        }
        catch (std::bad_alloc& e) {
            throw bad_alloc();
        }
        memset(data, 0, init_rows * init_columns * sizeof(Type));

        columns = init_columns;
        rows = init_rows;
    }

    template<class Type>
    matrix<Type>::matrix(const matrix& other)
    {
        try {
            data = new Type[other.rows * other.columns];
        }
        catch (std::bad_alloc& e) {
            throw bad_alloc();
        }
        rows = other.rows;
        columns = other.columns;

        copy(this->begin(), other.begin(), other.end());
    }

    template<class Type>
    matrix<Type>::matrix(matrix&& other)
    {
        data = other.data;
        rows = other.rows;
        columns = other.columns;
    }

    template<class Type>
    matrix<Type>&  matrix<Type>::operator =(const matrix& other)
    {
        if (this != &other) {
            try {
                delete[] data;
                data = new Type[other.columns * other.rows];
            }
            catch (std::bad_alloc& e)  {
                throw bad_alloc();
            }

            copy(this->begin(), other.begin(), other.end());
            rows = other.rows;
            columns = other.columns;
        }

        return *this;
    }

    template<class Type>
    matrix<Type>::~matrix()
    {
        delete[] data;
    }

    template<class Type>
    size_type matrix<Type>::get_rows()
    {
        return rows;
    }

    template<class Type>
    size_type matrix<Type>::get_columns()
    {
        return columns;
    }


    template<class Type>
    matrix_iterator<Type> matrix<Type>::begin()
    {
        return matrix_iterator<Type>(data);
    }


    template<class Type>
    const_matrix_iterator<Type> matrix<Type>::begin() const
    {
        return const_matrix_iterator<Type>(data);
    }


    template<class Type>
    matrix_iterator<Type> matrix<Type>::end()
    {
        return matrix_iterator<Type>(data + rows * columns);
    }


    template<class Type>
    const_matrix_iterator<Type> matrix<Type>::end() const
    {
        return const_matrix_iterator<Type>(data + rows * columns);
    }


    template<class Type>
    bool matrix<Type>::is_square() const
    {
        return rows == columns;
    }


    template<class Type>
    bool matrix<Type>::can_add(const matrix& other) const
    {
        return (rows == other.rows && columns == other.columns);
    }


    template<class Type>
    bool matrix<Type>::can_multiply(const matrix& other) const
    {
        return (columns == other.rows);
    }


    template<class Type>
    bool matrix<Type>::can_be_multiplied_by(const matrix& other) const
    {
        return (rows == other.rows);
    }

    template<class Type>
    matrix<Type> matrix<Type>::operator+(const matrix& other) const
    {
        if (!can_add(other)) {
            throw logical_error("Sizes of matrixes must match.");
        }
        matrix result(*this);

        add(result.begin(), other.begin(), other.end());

        return result;
    }


    template<class Type>
    matrix<Type>& matrix<Type>::operator+=(const matrix& other)
    {
        if (!can_add(other)) {
            throw logical_error("Sizes of matrixes must match.");
        }
        add(begin(), other.begin(), other.end());

        return *this;
    }

    template<class Type>
    matrix<Type> matrix<Type>::operator-(const matrix& other) const
    {
        if (!can_add(other)) {
            throw logical_error("Sizes of matrixes must match.");
        }
        matrix result(*this);
        deduct(result.begin(), other.begin(), other.end());

        return result;
    }

    template<class Type>
    matrix<Type>& matrix<Type>::operator-=(const matrix& other)
    {
        if (!can_add(other)) {
            throw logical_error("Sizes of matrixes must match.");
        }
        deduct(begin(), other.begin(), other.end());

        return *this;
    }

    template<class Type>
    matrix<Type> matrix<Type>::operator*(const matrix& other) const
    {
        if (!can_multiply(other)) {
            throw logical_error("Column number of this first object must match row number of second!");
        }

        matrix buffer = other.transposition();
        matrix result = matrix(rows, other.columns);

        for (size_type i = 0; i < result.rows; ++i) {
            for (size_type j = 0; j < result.columns; ++j) {
                matrix_iterator<Type> it(result.data + i * result.columns + j);
                matrix_iterator<Type> this_it(data + i * columns);
                matrix_iterator<Type> other_it(buffer.data + j * buffer.columns);

                for (size_type k = 0; k < other.rows; ++k, ++this_it, ++other_it) {
                    *it += (*this_it) * (*other_it);
                }
            }
        }

        return result;
    }

    template<class Type>
    matrix<Type> matrix<Type>::operator*(const int number) const
    {
        matrix result(*this);
        multiply(result.begin(), result.end(), number);

        return result;
    }

    template<class Type>
    matrix<Type> matrix<Type>::operator*(const double number) const
    {
        matrix result = matrix(this);
        multiply(result.begin(), result.end(), number);

        return result;
    }

    template<class Type>
    matrix<Type>& matrix<Type>::operator*=(const matrix& other)
    {
        if (!can_multiply(other)) {
            throw logical_error("Column number of this first object must match row number of second!");
        }

        *this = (*this) * other;

        return *this;
    }

    template<class Type>
    matrix<Type>& matrix<Type>::operator*=(const int number)
    {
        multiply(begin(), end(), number);

        return *this;
    }

    template<class Type>
    matrix<Type>& matrix<Type>::operator*=(const double number)
    {
        multiply(begin(), end(), number);

        return *this;
    }

    template<class Type>
    matrix<Type> matrix<Type>::in_power_of(const unsigned number) const
    {
        matrix result(*this);

        if (number == 0) {
            memset(data, 0, rows * columns * sizeof(Type));
        }

        for (unsigned i = 1; i < number; ++i) {
            result *= *this;
        }

        return result;
    }

    template<class Type>
    matrix<Type> matrix<Type>::transposition() const
    {
        matrix result = matrix(columns, rows);
        for (size_type i = 0; i < result.rows; ++i) {
            for (size_type j = 0; j < result.columns; ++j) {
                result.data[i * result.columns + j] = data[j * columns + i];
            }
        }

        return result;
    }


    template<class T>
    std::istream& operator>>(std::istream& source, matrix<T>& matr)
    {
        for (auto it = matr.begin(); it != matr.end(); ++it) {
            source >> *it;
        }

        return source;
    }


    template<class Type>
    void matrix<Type>::read(std::istream& source)
    {
        source >> *this;
    }


    template<class T>
    std::ostream& operator<<(std::ostream& destination, const matrix<T>& matr)
    {
        size_type k = 1;
        for (auto it = matr.begin(); it != matr.end(); ++it, ++k) {
            destination << *it << " ";
            if (k % matr.columns == 0) {
                destination << std::endl;
            }
        }

        return destination;
    }


    template<class Type>
    void matrix<Type>::print(std::ostream& destination) const
    {
        destination << *this;
    }


    template<class Type>
    Type& matrix<Type>::at(const size_type row, const size_type column) const
    {
        if (row > rows || column > columns) {
            throw out_of_range();
        }
        return data[row * columns + column];
    }

}
#endif // MATRIX_H
