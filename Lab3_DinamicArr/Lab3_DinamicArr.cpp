#include <iostream>
#include <string>

void print(int *arr) {
	for (int i = 1; i < arr[0]; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << "\n\n";
}


void push_back(int *&arr, int num) {
	int len = arr[0];
	arr[0]++;
	int *new_arr = new int[len+1];
	for (int i = 0; i < len; i++) {
		new_arr[i] = arr[i];
	}
	new_arr[len] = num;
	delete[] arr;
	arr = new_arr;
}

void task_3(int *data) {
	int ctn = data[0];
	for (int i = 1; i <= ctn; i++) {
		for (int j = 1; j <= ctn - 1 - i; j++) {
			int a = 0, b = 0, ctn = 0;
			// get summ data[j]
			std::string s = std::to_string(data[j]);
			for (char i : s) {
				if (ctn == 1) {
					a += std::stoi(std::to_string(i));
					ctn = 0;
				}
				else {
					ctn = 1;
				}
			}
			// get summ data[j+1]
			ctn = 0;
			s = std::to_string(data[j+1]);
			for (char i : s) {
				if (ctn == 1) {
					b += std::stoi(std::to_string(i));
					ctn = 0;
				}
				else {
					ctn = 1;
				}
			}

			if (a > b) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}

void std_sort (int *data) {
	int ctn = data[0];
	for (int i = 1; i <= ctn; i++) {
		for (int j = 1; j <= ctn - 1 - i; j++) {
			if (data[j] < data[j + 1]) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}

void task_4(int *data) {
	std_sort(data);
	int ctn = data[0];
	for (int i = 1; i <= ctn; i++) {
		for (int j = 1; j <= ctn - 1 - i; j++) {
			int a = 0, b = 0, ctn = 0;
			// get summ data[j]
			std::string s = std::to_string(data[j]);
			for (char i : s) {
				a = std::stoi(std::to_string(i));
			}

			// get summ data[j+1]
			ctn = 0;
			s = std::to_string(data[j + 1]);
			for (char i : s) {
				b = std::stoi(std::to_string(i));
			}

			if (a > b) {
				std::swap(data[j], data[j + 1]);
			}
		}
	}
}

int main()
{
	int num;
	int* arr = new int[1]{ 1 };  // data[0] - size of array with data[0]
	std::string s;
	bool run = true;
	std::cout << "Enter menu num: ";
	std::cin >> num;
	while (run) {
		switch (num)
		{
		case 1:
			// input nums
			std::cout << "To end input enter '-'\nData[" << arr[0] - 1 << "]: ";
			std::cin >> s;
			while (s != "-") {
				try {
					push_back(arr, std::stoi(s));
				}
				catch (std::invalid_argument e) {
					break;
				}

				std::cout << "Data[" << arr[0] - 1 << "]: ";
				std::cin >> s;
			}
			std::cout << '\n';
			break;
		case 2:
			print(arr);
			break;
		case 3:
			task_3(arr);
			print(arr);
			break;
		case 4:
			task_4(arr);
			print(arr);
			break;
		case 5:
			run = false;
		}

		if (run) {
			std::cout << "Enter menu num: ";
			std::cin >> num;
		}
	}
	

	delete [] arr;
	return 0;
}
