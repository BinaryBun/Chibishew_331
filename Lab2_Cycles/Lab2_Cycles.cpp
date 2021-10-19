#include <iostream>


int factorial(int num, int rez) {
    if (num != 0) {
        rez *= num;
        num--;
        factorial(num, rez);
    }
    else {
        return rez;
    }
}


void task_1() {
    std::cout << "===================================================== TASK 1 =====================================================\n";

    int num;
    std::cout << "Enter num: ";
    std::cin >> num;

    for (int i = 0; i <= num; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << j << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void task_2() {
    std::cout << "===================================================== TASK 2 =====================================================\n";

    int n, k;
    std::cout << "Enter n%k: ";
    std::cin >> n >> k;

    if (k <= n) {
        std::cout << "Answer: " << float(factorial(n, 1)) / (factorial(n - k, 1) * factorial(k, 1)) << "\n\n";
    }
    else {
        std::cout << "K can't be greater than N\n\n";
    }

}

void task_3() {
    std::cout << "===================================================== TASK 3 =====================================================\n";
    std::cout << "To end input enter 0\n" << "Enter num:\n";
    int summ = 0, num, ctn = 0;
    std::cin >> num;
    while (num != 0) {
        ctn++;
        summ += num;
        std::cin >> num;
    }
    std::cout << "Answer: " << double(summ) / ctn << "\n\n";
}

int main() {
    int num;
    bool run = true;

    while (run) {
        std::cout << "====================================================== MENU ======================================================\n";
        std::cout << "Enter menu num: ";
        std::cin >> num;
        std::cout << '\n';

        switch (num)
        {
        case 1:
            task_1();
            break;

        case 2:
            task_2();
            break;

        case 3:
            task_3();
            break;

        case 4:
            run = false;
            break;
        }
    }
}


