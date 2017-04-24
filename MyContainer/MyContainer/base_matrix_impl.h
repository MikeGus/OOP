#ifndef BASE_MATRIX_IMPL_H
#define BASE_MATRIX_IMPL_H

#include "base_matrix.h"

namespace my_cont {

    bool base_matrix::is_square() const
    {
        return rows == columns;
    }

    bool base_matrix::can_add(const base_matrix& other) const
    {
        return (rows == other.rows && columns == other.columns);
    }

    bool base_matrix::can_multiply(const base_matrix& other) const
    {
        return (columns == other.rows);
    }

    bool base_matrix::can_be_multiplied_by(const base_matrix& other) const
    {
        return (rows == other.rows);
    }

}
#endif // BASE_MATRIX_IMPL_H
