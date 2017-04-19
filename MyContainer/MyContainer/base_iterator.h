#ifndef BASE_ITERATOR_H
#define BASE_ITERATOR_H

#include "my_cont_namespace.h"
#include <cstddef>

namespace my_cont {

    template<class Type>
    class base_iterator {
        public:
            base_iterator() = default;
            base_iterator(const base_iterator& other);
            virtual ~base_iterator() = default;

            base_iterator& operator =(const base_iterator& other);

            base_iterator& operator ++();
            base_iterator operator ++(int);
            base_iterator& operator --();
            base_iterator operator --(int);

            bool operator ==(const base_iterator& other);
            bool operator !=(const base_iterator& other);

            std::ptrdiff_t operator -(const base_iterator& other);

        protected:
            base_iterator(Type* init_ptr);

            Type* ptr;
    };
}

#include "base_iterator_impl.h"

#endif // BASE_ITERATOR_H
