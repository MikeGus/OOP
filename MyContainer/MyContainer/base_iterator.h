#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H


#include <cstddef>


template<class Type>
class base_iterator {
    protected:
        base_iterator(Type* init_ptr);

        Type* ptr;

    public:
        base_iterator() = default;
        base_iterator(const base_iterator& other);
        virtual ~base_iterator() = default;

        base_iterator operator =(const base_iterator& other);

        base_iterator operator ++();
        base_iterator operator ++(int);
        base_iterator operator --();
        base_iterator operator --(int);

        bool operator ==(const base_iterator& other);
        bool operator !=(const base_iterator& other);

        std::ptrdiff_t operator -(const base_iterator& other);
};


template<class Type>
base_iterator<Type>::base_iterator(const base_iterator &other): ptr(other.ptr){}


template<class Type>
base_iterator<Type>::operator =(const base_iterator& other): ptr(other.ptr){}


template<class Type>
base_iterator<Type>::operator ++()
{
    ptr++;
    return *this;
}


template<class Type>
base_iterator<Type> base_iterator<Type>::operator ++(int)
{
    base_iterator tmp(this);
    ptr++;
    return tmp;
}


template<class Type>
base_iterator<Type>::operator --()
{
    ptr--;
    return *this;
}


template<class Type>
base_iterator<Type> base_iterator<Type>::operator --(int)
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
std::ptrdiff_t operator -(const base_iterator& other)
{
    return ptr - other.ptr;
}


template<class Type>
base_iterator<Type>::base_iterator(Type* init_ptr)
{
    ptr = init_ptr;
}


#endif // BASE_ITERATOR_H
