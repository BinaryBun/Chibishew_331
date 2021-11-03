#include <iostream>
#include <string>
#include <map>

void task_1() {
	std::cout << "Line: ";
	std::string line_1, line_2 = "";
	getline(std::cin, line_1);

	int len = line_1.length();
	int plus = 0;
	for (int i = 0; i < len; i++) {
		if (line_1[i] != ' ')
			line_2 += tolower(line_1[i]);
	}

	len = line_2.length();
	bool ans = true;
	for (int i = 0; i < len; i++) {
		if (line_2[i] != line_2[len - 1 - i]) {
			ans = false;
			break;
		}
	}
	std::cout << '\n';
	if (ans)
		std::cout << "Yes\n";
	else
		std::cout << "No\n";
}

void task_2() {
	// Boyer - Moore algorithm
	// declaring variables
	int ctn = 0; 

	std::string line;			// line
	std::cout << "Line: ";		// line
	getline(std::cin, line);	// line

	std::string word;			// word
	std::cout << "Subsring: ";	// word
	getline(std::cin, word);	// word

	std::string reverse_word = "";
	for (auto i : word) {
		reverse_word = i + reverse_word;
	}
	std::map<char, int> data;
	int now = word.length() - 1;
	bool is_word = true;
	// сreating a value map
	for (int i = (word.length() - 1); i >= 0; i--) {
		if (data.find(word[i]) == data.end()) {
			if (word[i] == word[word.length() - 1]) {
				data.insert(std::pair<char, int>((char)word[i], word.length()));
			}
			else {
				data.insert(std::pair<char, int>(word[i], ctn));
			}
		}
		else if (word[i] == word[word.length() - 1]) {
			data[word[i]] = ctn;
		}
		ctn++;
	}
	// find substrings
	std::cout << '\n';
	while (now < line.length()) {
		//std::cout << "- " << now << '\n';
		bool is_word = true;
		int run_now = now;
		for (auto i : reverse_word) {
			// std::cout << "+ " << i << '\n';
			if (i == line[run_now]) {
				run_now--;
			}
			else {
				is_word = false;
				break;
			}
		}
		//std::cout << "check_1\n";
		if (is_word) {
			//std::cout << "check_1.1\n";
			std::cout << "Index: " << now - word.length() + 1 << '\n';
			now += word.length();
		}
		else {
			//std::cout << "check_1.2\n" << line[run_now] << '\n';
			if (data.find(line[run_now]) != data.end()) {
				now += data[line[run_now]];
			}
			else {
				now += word.length();
			}
		}
	}
	/*
	for (auto item : data)
	{
		std::cout << item.first << " : " << item.second << std::endl; //Вывод ключей и значений
	}*/
}

void task_3() {
	// Caesar cipher
	int shift;
	std::string line;
	std::cout << "Line: ";
	getline(std::cin, line);
	std::cout << "Shift: ";
	std::cin >> shift;
	std::cout << "\nAnswer: ";
	for (auto i : line) {
		if ((('A' <= i) && (i <= 'Z')) || (('a' <= i) && (i <= 'z'))) {
			std::cout << (char)((int)i + shift);
		}
		else {
			std::cout << i;
		}
	}
	std::cout << '\n';
}

void task_4() {
	std::string line;
	std::cout << "Line: ";
	getline(std::cin, line);
	bool is_out = false;

	std::cout << "\nAnswer: ";
	for (auto i : line) {
		if (i == '"') {
			is_out = not is_out;
			if (not is_out)
				std::cout << " | ";
		}
		else {
			if (is_out)
				std::cout << i;
		}
	}
	std::cout << "\b\b";
}

int main()
{
	std::cout << "===================================================== TASK 1 =====================================================\n";
	task_1();
	std::cout << "===================================================== TASK 2 =====================================================\n";
	task_2();
	std::cout << "===================================================== TASK 3 =====================================================\n";
	task_3();
	std::cout << "===================================================== TASK 4 =====================================================\n";
	task_4();
}