#ifndef MATRIX_ITERATOR_IMPL_H
#define MATRIX_ITERATOR_IMPL_H

#include "matrix_iterator.h"

namespace my_cont {

    template<class Type>
    matrix_iterator<Type>::matrix_iterator(Type* init_ptr) : base_iterator<Type>(init_ptr)
    {
    }


    template<class Type>
    matrix_iterator<Type>::matrix_iterator(const matrix_iterator &other) : base_iterator<Type>(other.ptr)
    {
    }


    template<class Type>
    Type& matrix_iterator<Type>::operator *()
    {
        return *(this->ptr);
    }


    template<class Type>
    Type* matrix_iterator<Type>::operator ->()
    {
        return this->ptr;
    }
}

#endif // MATRIX_ITERATOR_IMPL_H
