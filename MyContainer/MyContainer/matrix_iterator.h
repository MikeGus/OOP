#ifndef MATRIX_ITERATOR_H
#define MATRIX_ITERATOR_H


#include "base_iterator.h"

namespace my_cont {

    template<class Type>
    class matrix_iterator : public base_iterator<Type>
    {
        private:
            matrix_iterator(Type* init_ptr);

        public:
            matrix_iterator(const matrix_iterator& other);

            Type& operator *();
            Type* operator ->();

            friend class matrix<Type>;
    };
}

#include "matrix_iterator_impl.h"

#endif // MATRIX_ITERATOR_H
