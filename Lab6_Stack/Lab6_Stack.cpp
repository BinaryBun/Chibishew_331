#include <iostream>
#include <string>
#include <map>
#include <stack>  // либа для работы со стеками


int main() {
    bool answ = true;
    std::map<char, char> data;
    data.insert(std::pair<char, int>('{', '}'));  // }
    data.insert(std::pair<char, int>('[', ']'));  // } пары комплементарности
    data.insert(std::pair<char, int>('(', ')'));  // }
    // main code
    std::stack <char> main_steck;
    std::string line_start;
    std::cin >> line_start;
    //cliar line
    for (auto i : line_start) {
        if (i == '{' or i == '(' or i == '[') {
            main_steck.push(i); // в вверх стека 
        }
        else if (i == '}' or i == ')' or i == ']') { 
            if (i == data[main_steck.top()]) {
                main_steck.pop();
            }
            else {
                answ = false;
                break;
            }
        }
    }
    // проверка пустоты стека
    if (not main_steck.empty())
        answ = false;
    // вывод ответа
    if (answ)
        std::cout << "-> Yes";
    else
        std::cout << "-> No";  
}
