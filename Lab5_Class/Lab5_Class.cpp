#include <iostream>
#include "Matrix.h"


int main() {
    // сложение матриц
    /* Matrix matr_1; // создание объекта класса
    matr_1.input(2, 3);
    Matrix matr_2;
    matr_2.input(2, 3);
    matr_1.sum(matr_2.ret_matr(), matr_2.get_rows(), matr_2.get_columns());
    matr_1.print(); */

    // умножение матриц
    /*Matrix matr_1;
    matr_1.input(2, 3);
    Matrix matr_2;
    matr_2.input(3, 2);
    matr_1.mult(matr_2.ret_matr(), matr_2.get_rows(), matr_2.get_columns());
    matr_1.print();
    */

    // след матрицы
    /* Matrix matr_1;
    matr_1.input(3, 3);
    std::cout << matr_1.trace() << '\n'; */

    // определитель матрицы
    /* Matrix matr_1;
    matr_1.input(4, 4);
    std::cout << matr_1.det(matr_1.get_rows(), matr_1.ret_matr()) << '\n'; */

    // умножение матрицы на число
    /* Matrix matr_1;
    matr_1.input(2, 2);
    matr_1.mult_by_num(4);
    matr_1.print(); */

    //количество столбцов
    /* Matrix matr_1;
    matr_1.input(2, 2);
    std::cout << matr_1.get_columns() << '\n';*/

    //количество строк
    /*Matrix matr_1;
    matr_1.input(2, 2);
    std::cout << matr_1.get_rows() << '\n'; */

    //вернуть (i,j) элемент
    /*Matrix matr_1;
    matr_1.input(3, 3);
    std::cout << matr_1.get_elem(1,2) << '\n'; */
}