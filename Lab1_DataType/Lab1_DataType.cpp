#include <iostream>
#include <bitset>

using std::cout;
using std::cin;
using std::endl;


void task_1() {
    cout << "===================================================== TASK 1 =====================================================" << endl;
    cout << "Chibishew M. A.\t211-331" << endl;
}

void task_2() {
    cout << "\n===================================================== TASK 2 =====================================================" << endl;
    cout << "min int = " << INT_MIN << "\t\t\tmax int = " << INT_MAX << "\t\t\tbyte size int = " << sizeof(int) << endl;
    cout << "min unsigned int = 0\t\t\tmax unsigned int = " << UINT_MAX << "\t\tbyte size unsigned int = " << sizeof(unsigned int) << endl;
    cout << "min short = " << SHRT_MIN << "\t\t\tmax short = " << SHRT_MAX << "\t\t\tbyte size short = " << sizeof(short) << endl;
    cout << "min unsigned short = 0\t\t\tmax unsigned short = " << USHRT_MAX << "\t\tbyte size unsigned short = " << sizeof(unsigned short) << endl;
    cout << "min long = " << LONG_MIN << "\t\t\tmax long = " << LONG_MAX << "\t\t\tbyte size long = " << sizeof(long) << endl;
    cout << "min long long = " << LLONG_MIN << "\tmax long long = " << LLONG_MAX << "\tbyte size long long = " << sizeof(long long) << endl;
    cout << "min double = " << DBL_MIN << "\t\tmax double = " << DBL_MAX << "\t\tbyte size double = " << sizeof(double) << endl;
    cout << "min char = " << CHAR_MIN << "\t\t\t\tmax char = " << CHAR_MAX <<  "\t\t\t\tbyte size char = " << sizeof(char) << endl;
    cout << "min bool = " << "false" << "\t\t\tmax bool = " << "true" << "\t\t\t\tbyte size bool = " << sizeof(bool) << endl;
}

void task_3() {
    cout << "\n===================================================== TASK 3 =====================================================" << endl;
    int num;
    cout << "Your num: ";
    cin >> num;
    cout << "Bin: 0b" << std::bitset<8 * sizeof(num)>(num) << endl;
    cout << "Hex: 0x" << std::hex << num << endl;
    cout << "Bool: " << bool(num) << endl;
    cout << "Double: " << double(num) << endl;
    cout << "Char: " << char(num) << endl;
}

void task_4() {
    cout << "\n===================================================== TASK 4 =====================================================" << endl;
    int a, b;
    cout << "Enter odds a&b (a*x=b): ";
    cin >> a >> b;
    // a*x=b => x=b/a
    cout << a << "*x=" << b << endl;
    cout << "x=" << b << '/' << a << endl;
    cout << "x=" << double(b) / a << endl;
}

void task_5() {
    cout << "\n===================================================== TASK 5 =====================================================" << endl;
    int x1, x2;
    cout << "Enter the coordinates of the line segment: ";
    cin >> x1 >> x2;

    cout << "The midpoint of the line is at the point with the coordinate: " << double(x1 + x2) / 2 << endl;
}


int main()
{
    task_1();
    task_2();
    task_3();
    task_4();
    task_5();

    return 0;
}
