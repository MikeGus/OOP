#include <iostream>
#include <fstream>
#include "matrix.h"


int main(void)
{
    try {
        my_cont::matrix<int> matrix(1000000,1000000);
    }
    catch (bad_alloc& e) {
        std::cout << "FIRST EXCEPTION: " << e.what() << std::endl;
    }

    my_cont::matrix<int> matrix_1(5,4);
    my_cont::matrix<int> matrix_2(4,3);

    try {
        std::cin >> matrix_1 >> matrix_2;
    }
    catch (reading_error& e) {
        std::cout << "SECOND EXCEPTION: " << e.what() << std::endl;
    }

    try {
        std::ifstream stream;
        std::ifstream stream_2;
        stream.open("C:/Programs/OOP/MyContainer/MyContainer/data.txt", std::ifstream::in);
        stream_2.open("C:/Programs/OOP/MyContainer/MyContainer/data_2.txt", std::ifstream::in);
        stream >> matrix_1;
        stream_2 >> matrix_2;
        stream.close();
        stream_2.close();
        std::cout << "MATRIXES:\n" << matrix_1 << std::endl << matrix_2 << std::endl;
    }
    catch(reading_error& e){
        std::cout << "THIRD EXCEPTION: " << e.what() << std::endl;
    }

    try {
        std::cout << "MATRIX MULT:\n" << matrix_2 * matrix_1;
    }
    catch (logical_error& e) {
        std::cout << "FORTH EXCEPTION: " << e.what() << std::endl;
    }

    my_cont::matrix<int> matrix_3;
    try {
        matrix_3 = matrix_1 * matrix_2;
        std::cout << "MATRIX:\n" << matrix_3 << std::endl;
    }
    catch (logical_error& e) {
        std::cout << "FIFTH EXCEPTION: " << e.what() << std::endl;
    }

    try {
        std::cout << "AT [0,0]: " << matrix_3.at(0,0) << std::endl;
    }
    catch (logical_error& e) {
        std::cout << "SIXTH EXCEPTION: "<< e.what() << std::endl;
    }

    try {
        std::cout << "AT [250,0]: " << matrix_3.at(250,0);
    }
    catch (out_of_range& e) {
        std::cout << "SEVENTH EXCEPTION: "<< e.what() << std::endl;
    }


    return 0;
}
