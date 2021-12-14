#include <iostream>
#include "Matrix.h"


int main() {
    Matrix matr_1;
    matr_1.input(2, 3);
    Matrix matr_2;
    matr_2.input(3, 2);

    matr_1.sum(matr_2.ret_matr(), matr_2.get_rows(), matr_2.get_columns());

    //matr_1.det(matr_1.get_rows(), matr_1.ret_matr());
    std::cout << matr_1.det(matr_1.get_rows(), matr_1.ret_matr());
    ///Matrix matr_2;
    ///matr_2.input(3, 2);
    ///matr_1.mult(matr_2.ret_matr(), matr_2.get_rows(), matr_2.get_columns());
    ///matr_1.print();
    //matr_1.print();
    //matr_1.mult_by_num(2);
    //matr_1.print();
    //std::cout << "Trace: " << matr_1.trace() << '\n';
    //std::cout << matr_1.ret_matr()[2];

    
}