#include "Matrix.h"
#include <iostream>

int main()
{
	bool num;
	// step one
	num = true;
	if (num)
		Matrix matr_0(2, 3);
	else {
		int data[6] = { 1, 2, 3, 4, 5, 6 };
		Matrix matr_0(2, 3, data);
	}

	//step two
	num = false;
	if (num) {
		int data[6] = { 1, 2, 3, 4, 5, 6 };
		Matrix matr_0(2, 3, data);

		int data_1[6] = { 6, 5, 4, 3, 2, 1 };
		matr_0.sum(2, 3, data_1);
	}
	else {
		int* data = new int[6] { 1, 2, 3, 4, 5, 6 };
		Matrix matr_0(2, 3, data);

		int* data_1 = new int[6] { 2, 2, 3, 4, 5, 6 };
		Matrix matr_1(2, 3, data_1);

		matr_0.sum(matr_1);
	}
	
	// step whree
	num = false;
	if (num) {
		int data[6] = { 1, 2, 3, 4, 5, 6 };
		Matrix matr_0(2, 3, data);

		int data_1[6] = { 6, 5, 4, 3, 2, 1 };
		matr_0.mult(3, 2, data_1);
	}
	else {
		int* data = new int[6]{ 1, 2, 3, 4, 5, 6 };
		Matrix matr_0(2, 3, data);

		int* data_1 = new int[6]{ 2, 2, 3, 4, 5, 6 };
		Matrix matr_1(3, 2, data_1);

		matr_0.mult(matr_1);
	}

	// step fore
	num = true;
	if (num) {
		Matrix matr_0(2, 3);
		matr_0.input(2, 3, true);  // auto

		std::cout << '\n';
		matr_0.print();
	}
	else {
		int* data = new int[6]{ 1, 2, 3, 4, 5, 6 };
		Matrix matr_0(2, 3);

		matr_0.input(2, 3, data);
		std::cout << '\n';
		matr_0.print();
	}
}