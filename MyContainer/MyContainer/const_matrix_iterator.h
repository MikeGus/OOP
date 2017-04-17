#ifndef CONST_MATRIX_ITERATOR_H
#define CONST_MATRIX_ITERATOR_H


#include "base_iterator.h"

namespace my_cont {

    template<class Type>
    class const_matrix_iterator : public base_iterator<Type>
    {

        private:
            const_matrix_iterator(Type*);

        public:
            const_matrix_iterator(const matrix_iterator<Type>& other);

            const Type& operator *();
            const Type* operator ->();

            friend class matrix<Type>;

    };

}

#include "const_matrix_iterator_impl.h"

#endif // CONST_MATRIX_ITERATOR_H
