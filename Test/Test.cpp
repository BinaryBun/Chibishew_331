#include <iostream>
#include <bitset>
#include <string>

int main()
{
    int num = 13;
    std::bitset<8 * sizeof(num)> bin_num(num);
    std::cout << bin_num.to_string() << '\n';
}
