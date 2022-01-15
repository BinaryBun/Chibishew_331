#include "Matrix.h"
#include "iostream"

Matrix::Matrix()
{
	/*// инициализируем матрицу
	this->matrix = new int [tmp_row*tmp_col];
	// записываем размерность матрицы
	this->row = tmp_row;
	this->col = tmp_col;*/
	this->row = 0;
	this->col = 0;

	this->matrix = nullptr;
}

Matrix::~Matrix()
{
	// удаление массива матрицы из памяти
	if (this->matrix != nullptr)
		delete this->matrix;
}

void Matrix::input(int tmp_row, int tmp_col)
{
	std::cout << "Enter matrix:\n";
	this->matrix = new double[tmp_row * tmp_col];  // создаём исходный пустой массив
	for (int i = 0; i < tmp_row * tmp_col; i++)
		std::cin >> *&this->matrix[i];

	this->col = tmp_col;
	this->row = tmp_row;
	std::cout << '\n';
}

void Matrix::print()
{
	std::cout << "\nMatrix " << this->col << 'x' << this->row << ":\n";
	for (int i = 0; i < this->row; i++) {
		for (int j = 0; j < this->col; j++) {
			std::cout << this->matrix[i * this->col + j] << ' ';
		}
		std::cout << "\n";
	}
	std::cout << '\n';
}

int Matrix::get_columns() {
	return this->col;
}

int Matrix::get_rows() {
	return this->row;
}

int Matrix::get_elem(int i, int j) {
	return this->matrix[i * this->col + j];
}

void Matrix::mult_by_num(double num)
{
	for (int i = 0; i < this->row * this->col; i++)
		*&this->matrix[i] *= num;
}

int Matrix::trace()
{
	if (this->col == this->row) {  // проверка на дурака
		int summ = 0;
		for (int i = 0; i < this->col; i++) {
			for (int j = 0; j < this->row; j++) {
				if ((i == j) or (j == this->col - i - 1)) {
					summ += this->matrix[i * this->col + j];
					//std::cout << this->matrix[i * this->col + j] << '\n';
				}
			}
		}
		return summ;
	}
	else {
		std::cout << "MATRIX INCORRECT\n";
		return -1;
	}

}

void Matrix::sum(double matrix_2[], int row_2, int col_2)
{
	if ((this->row == row_2) and (this->col == col_2)) {  // проверка на дурака
		for (int i = 0; i < this->row * this->col; i++) {
			this->matrix[i] += matrix_2[i];
		}
	}
	else {
		std::cout << "MATRIX INCORRECT\n";
	}
}

void Matrix::mult(double matrix_2[], int row_2, int col_2)
{
	if (this->col == row_2) {
		double* res = new double[this->row * col_2];
		double summ = 0;
		for (int i = 0; i < this->row; i++) {
			for (int j = 0; j < col_2; j++) {
				summ = 0;
				for (int k = 0; k < this->col; k++) {
					summ += this->matrix[i * this->col + k] * matrix_2[k * col_2 + j];
				}
				res[i * col_2 + j] = summ;
			}
		}
		// копирование временной матрицы в this->matrix
		delete this->matrix;
		this->matrix = res;
		this->col = col_2;
		//delete res;
	}
	else {
		std::cout << "MATRIX INCORRECT\n";
	}
}

int Matrix::det(int rang, int matr[])
{
	//путём вычитания по строке
	if (this->col == this->row) {  // проверка на дурака
		int summ = 0;
		int ctn = 0;
		if (rang != 3) {
			for (int i = 0; i < rang; i++) {
				ctn = 0;
				int* new_matr = new int[(rang - 1) * (rang - 1)];
				for (int rows = 0; rows < rang; rows++) {
					for (int cols = 0; cols < rang; cols++) {
						if (rows != 0 and cols != i) {
							new_matr[ctn] = matr[rows * rang + cols];
							ctn++;
							//std::cout << matr[rows * rang + cols] << ' ';
						}
					}
					//std::cout << '\n';
				}
				if (i % 2 == 0)
					summ += matr[i] * det(rang - 1, new_matr);
				else
					summ -= matr[i] * det(rang - 1, new_matr);

				delete[] new_matr;
			}

			return summ;
		}
		else {
			return det_3(matr);
		}
	}
	else {
		std::cout << "BAKA!!";
		return -1;
	}
}

int Matrix::det_3(int matr[]) {
	//развёрнутый метод Саррюса
	int diagonal = 1;
	int summ = 0;
	for (int step = 0; step < 3; step++) {
		// убывающая диагональ
		for (int i = 0; i < 3 + 3 - 1; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j + step) {
					diagonal *= matr[(i * 3 + j) % 9];
					//std::cout << mat_1[(i * cols1 + j) % 9] << '\n';
				}
			}
		}
		summ += diagonal;
		diagonal = 1;
		//возрастающая диагональ
		for (int i = 0; i < 3 + 3 - 1; i++) {
			for (int j = 0; j < 3; j++) {
				if (3 - i - 1 + step == j) {
					diagonal *= matr[(i * 3 + j) % 9];
					//std::cout << mat_1[(i * cols1 + j) % 9] << '\n';
				}
			}
		}
		summ -= diagonal;
		diagonal = 1;
	}
	//std::cout << "Answer: " << summ;
	return summ;
}

double* Matrix::ret_matr()
{
	return &this->matrix[0];
}

