#include <iostream>

class Lab4
{   
    public:
        int cols1, cols2, rows1, rows2;
        int *mat_1 = new int[rows1 * cols1];
        int *mat_2 = new int[rows2 * cols2];

    private:
        void print(int res[], int col, int row) {
            std::cout << "Answer:\t";
            for (int i = 0; i < row; i++) {
                for (int j = 0; j < col; j++) {
                    std::cout << res[i* col + j] << ' ';
                }
                std::cout << "\n\t";
            }
        }

    public:
        void sum() {
            int* res = new int[rows1 * cols1];

            for (int i = 0; i < rows1 * cols1; i++) {
                res[i] = mat_1[i] + mat_2[i];
            }
            print(res, cols1, rows1);
        }

        void mult() {
            int* res = new int[rows1 * cols2];
            int summ = 0;
            for (int i = 0; i < rows1; i++) {
                for (int j = 0; j < cols2; j++) {
                    summ = 0;
                    //std::cout << i << j << '\n';
                    for (int k = 0; k < cols1; k++) {
                        summ += mat_1[i * cols1 + k] * mat_2[k * cols2 + j];
                        //std::cout << mat_1[i * cols1 + k] << '*' << mat_2[k * cols2 + j] << '\n' << summ << '\n;
                    }
                    res[i * cols2 + j] = summ;
                    //std::cout << i << j << ' ';
                }
                //std::cout << "-------\n";
            }
            print(res, cols2, rows1);
        }

        void trace() {
            int summ = 0;
            for (int i = 0; i < cols1; i++) {
                for (int j = 0; j < cols1; j++) {
                    if ((i == j) or (j == cols1 - i-1)) {
                        summ += mat_1[i * cols1 + j];
                        std::cout << mat_1[i * cols1 + j] << '\n';
                    }
                }   
            }
            std::cout << "Answer: " << summ;
        }

        void det() {
            //развёрнутый метод Саррюса
            int diagonal = 1;
            int summ = 0;
            for (int step = 0; step < cols1; step++) {
                // убывающая диагональ
                for (int i = 0; i < cols1 + cols1 - 1; i++) {
                    for (int j = 0; j < cols1; j++) {
                        if (i == j + step) {
                            diagonal *= mat_1[(i * cols1 + j) % 9];
                            //std::cout << mat_1[(i * cols1 + j) % 9] << '\n';
                        }
                    }
                }
                summ += diagonal;
                diagonal = 1;
                //возрастающая диагональ
                for (int i = 0; i < cols1 + cols1 - 1; i++) {
                    for (int j = 0; j < cols1; j++) {
                        if (cols1 - i - 1 + step == j) {
                            diagonal *= mat_1[(i * cols1 + j) % 9];
                            //std::cout << mat_1[(i * cols1 + j) % 9] << '\n';
                        }
                    }
                }
                summ -= diagonal;
                diagonal = 1;
            }
            std::cout << "Answer: " << summ;
        }

        void muit_by_num(int num) {
            int* res = new int[rows1 * cols1];

            for (int i = 0; i < rows1 * cols1; i++) {
                res[i] = mat_1[i] * num;
            }
            print(res, cols1, rows1);
        }

        void input() {
            for (int i = 0; i < rows1 * cols1; i++) {
                std::cin >> *&mat_1[i];
            }
            print(mat_1, cols1, rows1);
        }

        double get_elem(int i, int j) {
            return mat_1[i * cols1 + j];
        }
};

int main()
{
    Lab4 task1;
    task1.cols1 = 3;
    task1.rows1 = 3;
    task1.cols2 = 1;
    task1.rows2 = 3;

    task1.mat_1 = new int[task1.rows1 * task1.cols1] {-2, 12, 1, 
                                                      1, 3, -5, 
                                                      2, 4, 5};
    task1.mat_2 = new int[task1.rows2 * task1.cols2] {1, 
                                                      2, 
                                                      3};

    //task1.sum();
    //task1.mult();
    //task1.trace();
    //task1.det();
    //task1.muit_by_num(5);
    //task1.input();
    //std::cout << task1.get_elem(1, 2);
}