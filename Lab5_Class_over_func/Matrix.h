#pragma once
class Matrix
{
private:
	int col;
	int row;
	int* element;

public:
	Matrix();
	Matrix(int i, int j);
	Matrix(int i, int j, const int* arr);
	Matrix(const Matrix& orig);
	~Matrix();

	void sum(int row, int col, const int* arr);
	void sum(Matrix second);

	void mult(int row, int col, const int* arr);
	void mult(Matrix second);

	void input(int i, int j, bool flag);
	void input(int i, int j, const int* arr);

	void print();
};


