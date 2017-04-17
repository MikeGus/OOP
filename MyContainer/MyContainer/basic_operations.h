#ifndef ADD_H
#define ADD_H

#include "matrix_iterator.h"
#include "const_matrix_iterator.h"

namespace my_cont {

    template<class Type>
    void add(matrix_iterator<Type> result, const_matrix_iterator<Type> begin, const_matrix_iterator<Type> end)
    {
        for (auto it = begin; it != end; ++it, ++result) {
            *result += *it;
        }
    }

    template<class Type>
    void deduct(matrix_iterator<Type> result, const_matrix_iterator<Type> begin, const_matrix_iterator<Type> end)
    {
        for (auto it = begin; it != end; ++it, ++result) {
            *result -= *it;
        }
    }

    template<class Type>
    void copy(matrix_iterator<Type> result, const_matrix_iterator<Type> begin, const_matrix_iterator<Type> end)
    {
        for (auto it = begin; it != end; ++it, ++result) {
            *result = *it;
        }
    }

    template<class Type>
    void multiply(matrix_iterator<Type> result, const_matrix_iterator<Type> begin, const_matrix_iterator<Type> end)
    {
        for (auto it = begin; it != end; ++it, ++result) {
            *result *= *it;
        }
    }

    template<class Type>
    void multiply(matrix_iterator<Type> result_begin, matrix_iterator<Type> result_end, const int value)
    {
        for (auto it = result_begin; it != result_end; ++it) {
            *it *= value;
        }
    }

    template<class Type>
    void multiply(matrix_iterator<Type> result_begin, matrix_iterator<Type> result_end, const double value)
    {
        for (auto it = result_begin; it != result_end; ++it) {
            *it *= value;
        }
    }
}

#endif // ADD_H
