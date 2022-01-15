#include <iostream>
#include <string>
#include <bitset>

struct MyStruct
{
    std::string surname, name, age;
    int int_age;

    MyStruct(std::string one, std::string two, int three) {
        this->int_age = three;
        std::bitset<8 * sizeof(three)> bin_age(three);
        this->age = bin_age.to_string();
        this->name = one;
        this->surname = two;
    }

    std::string print() {
        return "[" + this->name + ", " + this->surname + ", " + std::to_string(this->int_age) + "]";
    }
    
    auto operator[] (std::string colum) {
        if (colum == "name") { return this->name; }  // <- оставить
        else if (colum == "surname") { return this->surname; }
        else if (colum == "age") { return this->age; }
    }
};

template <typename T>
void qsort(T* mas, int size) {
    int i = 0;
    int j = size - 1;
    auto mid = mas[size / 2];
    do {
        while (mas[i] < mid) {
            i++;
        }
        while (mas[j] > mid) {
            j--;
        }
        if (i <= j) {
            auto tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);
    if (j > 0) {
        qsort(mas, j + 1);
    }
    if (i < size) {
        qsort(&mas[i], size - i);
    }
}

template <typename T>
void qsort(T* mas, int size, std::string colum) {
    int i = 0;
    int j = size - 1;
    
    auto mid = mas[size / 2][colum];  // <- статическиое обновление
    do {
        // если сделать провеку на тип данных?
        while (mas[i][colum] < mid) {  // <- динамическое обновление
            i++;
        }
        while (mas[j][colum] > mid) {  // <- динамическое обновление
            j--;
        }
        if (i <= j) {
            // свап элементов
            auto tmp = mas[i];  // <- оставить как есть
            mas[i] = mas[j];  // <- оставить как есть
            mas[j] = tmp;  // <- оставить как есть

            i++;
            j--;
        }
    } while (i <= j);

    if (j > 0) {
        qsort(mas, j + 1, colum);
    }
    if (i < size) {
        qsort(&mas[i], size - i, colum);
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    // ----------
    std::string col = "surname";
    std::cout << "Exampl <MyStruct> by " << col << ":\n";
    MyStruct data_0[10] =   {{"Софья", "Демьянова", 50},
                            {"Майя", "Молчанова", 67},
                            {"Фёдор", "Смирнов", 37},
                            {"Артём", "Афанасьев", 29},
                            {"Варвара", "Горбунова", 1},
                            {"Марк", "Сергеев", 78},
                            {"Анна", "Никонова", 52},
                            {"Елизавета", "Романова", 16},
                            {"Элина", "Медведева", 23},
                            {"Полина", "Иванова", 93}};
    qsort(data_0, 10, col);
    for (auto i : data_0) { std::cout << "\t\x1b[36m" << i.print() << "\n\x1b[37m"; }
    // ----------
    std::cout << "\nExampl <char>: ";
    char data_1[4] = { 'a', 'c', 'b', 'h' };
    qsort(data_1, 4);
    for (auto i : data_1) { std::cout << "\x1b[36m" << i << "\x1b[37m "; }
    // ----------
    std::cout << "\n\nExampl <int>: ";
    int data_2[4] = { 12, 34, 0, -12 };
    qsort(data_2, 4);
    for (auto i : data_2) { std::cout << "\x1b[36m" << i << "\x1b[37m "; }
    // ----------
    std::cout << "\n\nExampl <float>: ";
    float data_3[4] = { 12.1, 34.3, 34.2, -12.0 };
    qsort(data_3, 4);
    for (auto i : data_3) { std::cout << "\x1b[36m" << i << "\x1b[37m "; }
    std::cout << "\n";
}
