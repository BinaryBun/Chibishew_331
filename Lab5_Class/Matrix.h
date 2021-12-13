#pragma once
class Matrix
{
//модификаторы доступа
private:
	int col, row;
	int* matrix;
protected:
	//
public:
	Matrix();  // конструктор по умолчанию
	~Matrix();  // деструктор

	void input(int tmp_row, int tmp_col);  // воод матрицы с клавиатуры
	void print();  // вывод матрицы
	int get_columns();  // получение колонок
	int get_rows();  // получение столбцов
	int get_elem(int i, int j);  // получение элемента
	void mult_by_num(double num);  // умножение матрицы на число
	int trace();  // след матрицы
	void sum(int matrix_2[], int row_2, int col_2);  // сумма матриц
	void mult(int matrix_2[], int row_2, int col_2);  // перемнодение матриц
	int det(int rang, int matr[]);  // оперделитель матрицы

	int det_3(int matr[]);
	int* ret_matr();
};

