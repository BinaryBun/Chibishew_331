#include "Matrix.h"
#include <iostream>
#include <ctime>

Matrix::Matrix()
{
	row = 0;
	col = 0;
	element = nullptr;
}

Matrix::Matrix(const Matrix& orig)
{
	this->row = orig.row;
	this->col = orig.col;

	if (orig.element != nullptr)
		this->element = new int[this->row * this->col];
	else this->element = nullptr;

	if (this->element != nullptr)
		for (int i = 0; i < this->row * this->col; i++)
			this->element[i] = orig.element[i];
}

Matrix::Matrix(int i, int j) 
{
	this->row = i;
	this->col = j;
}

Matrix::Matrix(int i, int j, const int* arr)
{
	this->row = i;
	this->col = j;
	element = new int[row * col];
	for (int k = 0; k < row * col; k++)
		element[k] = arr[k];
}

Matrix::~Matrix()
{
	if (this->element != nullptr)
		delete[] this->element;
}

void Matrix::sum(int row, int col, const int* arr)
{
	if ((row * col) != (this->row * this->col))
	{
		std::cout << "\nMatrices dont equal\n";
		return;
	}

	int* res = new int[this->row * this->col];

	for (int i = 0; i < this->row * this->col; i++)
		res[i] = this->element[i] + arr[i];

	std::cout << "Answer:\n";
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << res[i * this->col + j] << " "; 
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Matrix::sum(Matrix second)
{	
	if ((this->row != second.row) && (this->col != second.col))
	{
		std::cout << "\nMatrix sizes are not equal\n";
		return;
	} 
	
	int* res = new int[this->row * this->col];

	for (int i = 0; i < this->row * this->col; i++)
		res[i] = this->element[i] + second.element[i];

	std::cout << "Answer:\n";
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << res[i * this->col + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
	return;
}

void Matrix::mult(int row, int col, const int* arr)
{
	if (this->col != row)
	{
		std::cout << "\nFirst col dont equal second row\n";
		return;
	}

	int* res = new int[this->row * col];
	int i, j, k;

	for (i = 0; i < this->row * col; i++)
		res[i] = 0;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < col; j++)
		{
			for (k = 0; k < this->col; k++)
				res[i * col + j] += this->element[i * this->col + k] * arr[k * col + j];
		}
	}

	std::cout << "Answer:\n";
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < col; j++)
			std::cout << res[i * col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;
}

void Matrix::mult(Matrix second)
{
	if (this->col != second.row)
	{
		std::cout << "\nFirst col dont equal second row\n";
		return;
	}

	int* res = new int[this->row * second.col];
	int i, j, k;

	for (i = 0; i < this->row * second.col; i++)
		res[i] = 0;
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
		{
			for (k = 0; k < this->col; k++)
				res[i * second.col + j] += this->element[i * this->col + k] * second.element[k * second.col + j];
		}
	}

	std::cout << "Answer:\n";
	for (i = 0; i < this->row; i++)
	{
		for (j = 0; j < second.col; j++)
			std::cout << res[i * second.col + j] << " ";
		std::cout << std::endl;
	}
	delete[] res;
}

void Matrix::input(int i, int j, bool _auto_)
{
	srand((unsigned)time(0));
	this->row = i;
	this->col = j;
	if (this->element != nullptr)
		delete[]this->element;
	this->element = new int[this->row * this->col];
	if (_auto_) {
		for (int k = 0; k < this->row * this->col; k++)
			element[k] = rand() % 10;
	}
	else {
		std::cout << "\nEnter matrix:\n";
		for (int k = 0; k < this->row * this->col; k++)
			std::cin >> this->element[k];
	}
}

void Matrix::input(int i, int j, const int* arr)
{
	this->row = i;
	this->col = j;
	if (this->element != nullptr)
		delete[]this->element;
	this->element = new int[this->row * this->col];
	for (int k = 0; k < this->row * this->col; k++)
		this->element[k] = arr[k];
}

void Matrix::print()
{
	std::cout << "Answer:\n";
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
			std::cout << this->element[i * this->col + j] << " ";
		std::cout << std::endl;
	}
	std::cout << std::endl;
}