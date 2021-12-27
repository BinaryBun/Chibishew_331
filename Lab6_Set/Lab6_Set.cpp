#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set <std::string> data_set;
    std::set <std::string> data_rep;
    std::string name;
    std::cout << "Enter student name: ";
    std::cin >> name;

    // заполнение множеств
    while (name != "-") {
        if (data_set.find(name) != data_set.end())
            data_rep.insert(name);
        data_set.insert(name);

        std::cout << "Enter student name: ";
        std::cin >> name;
    }

    //отчиска основного множества
    for (auto i : data_rep)
        data_set.erase(i);

    // вывод итогового множества
    std::cout << "\nAnswer:\n";
    for (auto i : data_set)
        std::cout << "\x1b[32m[+] " << i << "\x1b[37m\n";

    // вывод хитрых 
    for (auto i : data_rep)
        std::cout << "\x1b[31m[-] " << i << "\x1b[37m\n";

}

