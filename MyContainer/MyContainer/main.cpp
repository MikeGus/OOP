#include <iostream>
#include "matrix.h"

int main(void)
{
    my_cont::matrix<int> matrix(2,2);
    std::cin >> matrix;

    my_cont::matrix<int> matrix_3(matrix);
    matrix = matrix_3.in_power_of(3);

    std::cout << matrix_3;

    return 0;
}
