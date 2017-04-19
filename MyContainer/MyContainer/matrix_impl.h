#ifndef MATRIX_IMPL_H
#define MATRIX_IMPL_H

#include "matrix.h"

namespace my_cont {

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
            if (data) {
                delete[] data;
            }
            data = new Type[other.rows * other.columns];
        }
        catch (std::bad_alloc& e) {
            throw bad_alloc();
        }
        rows = other.rows;
        columns = other.columns;

        copy(this->begin(), other.cbegin(), other.cend());
    }

    template<class Type>
    matrix<Type>::matrix(matrix&& other)
    {
        data = other.data;
        rows = other.rows;
        columns = other.columns;

        other.rows = 0;
        other.columns = 0;
        other.data = nullptr;
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

            copy(this->begin(), other.cbegin(), other.cend());
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
    typename matrix<Type>::matrix_iterator matrix<Type>::begin()
    {
        return matrix_iterator(data);
    }


    template<class Type>
    typename matrix<Type>::const_matrix_iterator matrix<Type>::cbegin() const
    {
        return const_matrix_iterator(data);
    }


    template<class Type>
    typename matrix<Type>::matrix_iterator matrix<Type>::end()
    {
        return matrix_iterator(data + rows * columns);
    }


    template<class Type>
    typename matrix<Type>::const_matrix_iterator matrix<Type>::cend() const
    {
        return const_matrix_iterator(data + rows * columns);
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

        add(result.begin(), other.cbegin(), other.cend());

        return result;
    }


    template<class Type>
    matrix<Type>& matrix<Type>::operator+=(const matrix& other)
    {
        if (!can_add(other)) {
            throw logical_error("Sizes of matrixes must match.");
        }
        add(begin(), other.cbegin(), other.cend());

        return *this;
    }

    template<class Type>
    matrix<Type> matrix<Type>::operator-(const matrix& other) const
    {
        if (!can_add(other)) {
            throw logical_error("Sizes of matrixes must match.");
        }
        matrix result(*this);
        deduct(result.begin(), other.cbegin(), other.cend());

        return result;
    }

    template<class Type>
    matrix<Type>& matrix<Type>::operator-=(const matrix& other)
    {
        if (!can_add(other)) {
            throw logical_error("Sizes of matrixes must match.");
        }
        deduct(begin(), other.cbegin(), other.cend());

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
                matrix_iterator it(result.data + i * result.columns + j);
                matrix_iterator this_it(data + i * columns);
                matrix_iterator other_it(buffer.data + j * buffer.columns);

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
            if (source.fail()) {
                throw reading_error();
            }
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
        for (auto it = matr.cbegin(); it != matr.cend(); ++it, ++k) {
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
        if (row >= rows || column >= columns) {
            throw out_of_range("You tried to access position out of range.");
        }
        return data[row * columns + column];
    }
}


#endif // MATRIX_IMPL_H
