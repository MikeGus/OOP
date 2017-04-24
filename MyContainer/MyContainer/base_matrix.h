#ifndef BASE_MATRIX_H
#define BASE_MATRIX_H

#include <cstddef>

namespace my_cont {

    typedef size_t size_type;
    class base_matrix
    {
        public:
            explicit base_matrix() = default;
            explicit base_matrix(const base_matrix& other) = default;
            virtual ~base_matrix() = default;

            size_type get_rows() const;
            size_type get_columns() const;

            bool is_square() const;
            bool can_add(const base_matrix& other) const;
            bool can_multiply(const base_matrix& other) const;
            bool can_be_multiplied_by(const base_matrix& other) const;

        protected:
            size_type rows = 0;
            size_type columns = 0;
    };

}

#include "base_matrix_impl.h"

#endif // BASE_MATRIX_H
