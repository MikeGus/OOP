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
    matrix<Type>::matrix(const matrix& other) : base_matrix(other)
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
        matrix<Type> result(*this);
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

        matrix<Type> buffer = other.transposition();
        matrix<Type> result = matrix(rows, other.columns);

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
    matrix<Type> matrix<Type>::operator*(const Type number) const
    {
        matrix<Type> result(*this);
        multiply(result.begin(), result.end(), number);

        return result;
    }

    template<class Type>
    matrix<Type> operator *(const Type& value, const matrix<Type>& matr)
    {
        return matr * value;
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
    matrix<Type>& matrix<Type>::operator*=(const Type number)
    {
        multiply(begin(), end(), number);

        return *this;
    }

    template<class Type>
    matrix<Type> matrix<Type>::in_power_of(const unsigned number) const
    {
        matrix<Type> result(*this);

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
        matrix<Type> result = matrix(columns, rows);
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
    const Type& matrix<Type>::at(const size_type row, const size_type column) const
    {
        if (row >= rows || column >= columns) {
            throw out_of_range("You tried to access position out of range.");
        }
        return data[row * columns + column];
    }


    template<class Type>
    Type& matrix<Type>::at(const size_type row, const size_type column)
    {
        if (row >= rows || column >= columns) {
            throw out_of_range("You tried to access position out of range.");
        }
        return data[row * columns + column];
    }

    template<class Type>
    matrix<Type>::proxy::proxy(size_type init_columns, Type* init_data)
    {
        this->col_count = init_columns;
        this->data = init_data;
    }

    template<class Type>
    Type& matrix<Type>::proxy::operator[](size_type column)
    {
        if (this->col_count <= column) {
            throw out_of_range();
        }
        return this->data[column];
    }

    template<class Type>
    const Type& matrix<Type>::proxy::operator[](size_type column) const
    {
        if (this->col_count <= column) {
            throw out_of_range();
        }
        return this->data[column];
    }

    template<class Type>
    typename matrix<Type>::proxy matrix<Type>::operator[](const size_type row)
    {
        if (this->rows <= row) {
            throw out_of_range();
        }
        return proxy(this->columns, this->data + columns * row);
    }

    template<class Type>
    const typename matrix<Type>::proxy matrix<Type>::operator[](const size_type row) const
    {
        if (this->rows <= row) {
            throw out_of_range();
        }
        return proxy(this->columns, this->data + columns * row);
    }

    template<class Type>
    Type matrix<Type>::determinant() const
    {
        if (!is_square()) {
            throw logical_error("Matrix is not square.");
        }
        if (rows == 2) {
            return data[0] * data[3] - data[1] * data[2];
        }

        double d = 0;
        matrix<Type> sub_matrix(rows - 1, columns - 1);
        for(size_type c = 0; c < rows; ++c) {
            size_type subi = 0;
            for(size_type i = 1; i < rows; ++i) {
                size_type subj = 0;
                for(size_type j = 0; j < rows; ++j) {
                    if (j != c) {
                        sub_matrix[subi][subj] = data[i * columns + j];
                        subj++;
                    }
                }
                subi++;
            }
            d += (pow(-1, c) * data[c] * sub_matrix.determinant());
        }

        return d;
    }

    template <class Type>
    Type* matrix<Type>::find_column(size_type column) const
    {
        matrix<Type> buf_matrix(rows, columns + 1);
        for (size_type i = 0; i < rows; ++i) {
            for (size_type j = 0; j < columns; ++j) {
                buf_matrix[i][j] = (*this)[i][j];
            }
        }
        buf_matrix[column][columns] = (Type) 1;

        Type* ret_column = new Type[rows];
        memset(ret_column, 0, rows * sizeof(Type));

        for (size_type i = 0; i < rows; ++i) {
            // swap rows if nessasary
            if (fabs(buf_matrix[i][i]) < 1e-5) {
                for (size_type j = i + 1; j < rows; ++j) {
                    if (fabs(buf_matrix[j][j]) > 1e-5) {
                        matrix_iterator first_begin(buf_matrix.data + j * buf_matrix.columns);
                        matrix_iterator first_end(buf_matrix.data + (j + 1) * buf_matrix.columns);
                        matrix_iterator second_begin(buf_matrix.data + i * buf_matrix.columns);
                        swap(first_begin, first_end, second_begin);
                    }
                }
            }
            for (size_type j = i + 1; j < rows; ++j) {
                Type d = -buf_matrix[j][i] / buf_matrix[i][i];
                for (size_type k = 0; k <= columns; ++k) {
                    buf_matrix[j][k] += d * buf_matrix[i][k];
                }
            }
        }
        for (int i = rows - 1; i >= 0; --i) {
            Type res = 0;
            for (size_type j = 0; j < rows; ++j) {
                res += buf_matrix[i][j] * ret_column[j];
            }
            ret_column[i] = (buf_matrix[i][rows] - res) / buf_matrix[i][i];
        }

        return ret_column;
    }

    template <class Type>
    matrix<Type> matrix<Type>::inverse() const
    {
        if (fabs(determinant()) < 1e-5) {
            throw logical_error("Determinant is zero. Can't find inverse matrix.");
        }
        matrix<Type> res(*this);
        for (size_type i = 0; i < rows; ++i) {
            Type* col = find_column(i);
            for (size_type j = 0; j < rows; ++j) {
                res[j][i] = col[j];
            }
            delete[] col;
        }
        return res;
    }
}

#endif // MATRIX_IMPL_H
