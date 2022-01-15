#include <iostream>

class Matrix {
private:
    int size = 0;
    double* matrix;

public:
    void input() {
        std::cout << "Matrix size: ";
        std::cin >> this->size;  // хранится квадрат
        this->size *= this->size;

        this->matrix = new double[this->size];
        std::cout << "Matrix:\n";
        for (int i = 0; i < this->size; i++)
            std::cin >> this->matrix[i];
    }

    void input(int size_p) {
        this->size = size_p*size_p;
        this->matrix = new double[this->size];
        for (int i = 0; i < size_p; i++) {
            for (int j = 0; j < size_p; j++) {
                if (i == j or i+1 == j or i-1 == j) {
                    this->matrix[i*size_p + j] = rand() % (10 - 0);  // [0; 9)
                }
                else
                    this->matrix[i*size_p + j] = 0;
            }
        }
    }

    double trace() {
        int summ = 0;
        for (int i = 0; i < this->size; i++)
            summ += this->matrix[i];
        return summ;
    }



    void print() {
        for (int i = 0; i < sqrt(this->size); i++)
        {
            for (int j = 0; j < sqrt(this->size); j++)
                std::cout << this->matrix[i*int(sqrt(this->size)) + j] << ' ';
            std::cout << '\n';
        }
    }
};

int main()
{
    Matrix obj1;
    obj1.input(5);
    std::cout << obj1.trace() << '\n';
    obj1.print();

}
