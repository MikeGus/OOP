#ifndef CONST_MATRIX_ITERATOR_IMPL_H
#define CONST_MATRIX_ITERATOR_IMPL_H

#include "const_matrix_iterator.h"

namespace my_cont {

    template<class Type>
    const_matrix_iterator<Type>::const_matrix_iterator(Type* init_ptr) : base_iterator<Type>(init_ptr)
    {
    }


    template<class Type>
    const_matrix_iterator<Type>::const_matrix_iterator(const matrix_iterator<Type> &other) : base_iterator<Type>(other)
    {
    }


    template<class Type>
    const Type& const_matrix_iterator<Type>::operator *()
    {
        return *(this->ptr);
    }


    template<class Type>
    const Type* const_matrix_iterator<Type>::operator ->()
    {
        return this->ptr;
    }
}


#endif // CONST_MATRIX_ITERATOR_IMPL_H
