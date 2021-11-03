#include <iostream>
#include <string>

void task_1(std::string line, int point_location, int slash_location) {
    std::cout << line.substr(point_location + 1, line.length() - point_location) << '\n';
}

void task_2(std::string line, int point_location, int slash_location) {
    std::cout << line.substr(slash_location + 1, point_location - slash_location - 1) << '\n';
}

void task_3(std::string line, int point_location, int slash_location) {
    std::cout << line.substr(0, slash_location) << '\n';
}

void task_4(std::string line, int point_location, int slash_location) {
    std::cout << line[0] << '\n';
}

void task_5(std::string line, int point_location, int slash_location, std::string new_name) {
    std::string dir = line.substr(0, slash_location);
    std::string last_name = line.substr(slash_location + 1, line.length() - slash_location);
    const std::string command = "cd " + dir + " && ren " + last_name + " " + new_name;
    system(command.c_str());
}

void task_6(std::string line, int point_location, int slash_location) {
    std::string dir = line.substr(0, slash_location);
    std::string last_name = line.substr(slash_location + 1, line.length() - slash_location);
    std::string new_name = line.substr(slash_location + 1, point_location - slash_location - 1) + "_copy.";
    new_name += line.substr(point_location + 1, line.length() - point_location);
    const std::string command = "cd " + dir + " && copy " + last_name + " " + new_name;
    system(command.c_str());
}

int main()
{
    std::string line;
    std::string pass;
    int num;
    std::string new_name;
    std::cout << ">> Num: ";
    std::cin >> num;

    while (num != 7) {
        getline(std::cin, pass);  //cleen cmd
        std::cout << "Location: ";
        getline(std::cin, line);
        int point_location, slash_location;
        for (int i = line.length() - 1; i >= 0; i--) {
            if (line[i] == '.')
                point_location = i;

            if (line[i] == (char)92) {
                slash_location = i;
                break;
            }
        }

        switch (num){
        case 1:
            task_1(line, point_location, slash_location);
            break;
        case 2:
            task_2(line, point_location, slash_location);
            break;
        case 3:
            task_3(line, point_location, slash_location);
            break;
        case 4:
            task_4(line, point_location, slash_location);
            break;
        case 5:
            std::cout << "New_name: ";
            std::cin >> new_name;
            task_5(line, point_location, slash_location, new_name);
            break;
        case 6:
            task_6(line, point_location, slash_location);
            break;
        }

        std::cout << ">> Num: ";
        std::cin >> num;
    }
}
