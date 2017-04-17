#ifndef BASE_ITERATOR_IMPL_H
#define BASE_ITERATOR_IMPL_H

#include "base_iterator.h"

namespace my_cont {

    template<class Type>
    base_iterator<Type>::base_iterator(const base_iterator &other): ptr(other.ptr)
    {
    }


    template<class Type>
    base_iterator<Type>& base_iterator<Type>::operator =(const base_iterator<Type>& other)
    {
        this->ptr(other.ptr);
        return *this;
    }


    template<class Type>
    base_iterator<Type>& base_iterator<Type>::operator ++()
    {
        ptr++;
        return *this;
    }


    template<class Type>
    base_iterator<Type>& base_iterator<Type>::operator ++(int)
    {
        base_iterator tmp(this);
        ptr++;
        return tmp;
    }


    template<class Type>
    base_iterator<Type>& base_iterator<Type>::operator --()
    {
        ptr--;
        return *this;
    }


    template<class Type>
    base_iterator<Type>& base_iterator<Type>::operator --(int)
    {
        base_iterator tmp(this);
        ptr--;
        return tmp;
    }


    template<class Type>
    bool base_iterator<Type>::operator ==(const base_iterator& other)
    {
        return ptr == other.ptr;
    }


    template<class Type>
    bool base_iterator<Type>::operator !=(const base_iterator& other)
    {
        return ptr != other.ptr;
    }


    template<class Type>
    std::ptrdiff_t base_iterator<Type>::operator -(const base_iterator& other)
    {
        return ptr - other.ptr;
    }


    template<class Type>
    base_iterator<Type>::base_iterator(Type* init_ptr)
    {
        ptr = init_ptr;
    }
}

#endif // BASE_ITERATOR_IMPL_H
