#include <iostream>
#include <string>

void bubbles(int data[], int ctn) {
    for (int i = 0; i < ctn; i++) {
        for (int j = 0; j < ctn - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }

    std::cout << "\nAnswer: ";
    for (int i = 0; i < ctn; i++) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';
}

void counting_sort(int data[], int ctn) {
    std::cout << "\nAnswer: ";
    for (int i = (int)'a'; i <= (int)'z'; i++) {
        //std::cout << (char) i << ' ' << std::count(data, data + ctn, i) << '\n';
        for (int j = 0; j < std::count(data, data + ctn, i); j++) {
            std::cout << (char)i << " ";
        }
    }
    std::cout << '\n';
}

int merge_arrays(int c[], int a[], int b[], int len_a, int len_b) {
    //std::cout << '[';
    //for (int i = 0; i < len_a; i++) std::cout << a[i] << ' ';
    //std::cout << "]\n[";

    //for (int i = 0; i < len_b; i++) std::cout << b[i] << ' ';
    //std::cout << "]\n";

    int i = 0, j = 0, poz = 0;
    while ((i < len_a) and (j < len_b)) {
        if (a[i] < b[j]) {
            *&c[poz] = a[i];
            i++;
        }
        else {
            *&c[poz] = b[j];
            j++;
        }
        poz ++;
    }

    if (i < len_a) {
        for (int k = i; k < len_a; k++) {
            *&c[poz] = a[k];
            poz++;
        }
    }

    if (j < len_b) {
        for (int k = j; k < len_b; k++) {
            *&c[poz] = b[k];
            poz++;
        }
    }
    //std::cout << "--[";
    //for (int i = 0; i < len_a + len_b; i++) std::cout << c[i] << ' ';
    //std::cout << "]--\n";
    return len_a + len_b;
    
}

int merge_sort(int data[], int start, int stop, int merge_end[]) {
    //for (int a = start; a < stop; a++) std::cout << data[a] << ' ';
    //std::cout << '\n';
    if (stop - start == 1) {
        *&merge_end[0] = data[start];
        return 1;
    }
    else {
        int middle = start + ((stop - start) / 2);
        int left[1000];
        int right[1000];

        int run_len = merge_sort(data, start, middle, merge_end);
        int left_len = run_len;
        for (int i = 0; i < run_len; i++) {
            left[i] = merge_end[i];
        }

        run_len = merge_sort(data, middle, stop, merge_end);
        int right_len = run_len;
        for (int j = 0; j < run_len; j++) {
            right[j] = merge_end[j];
        }

        //std::cout << "left/right: " << left_len << ' ' << right_len << '\n';
        int len_mirge = merge_arrays(merge_end, left, right, left_len, right_len);
        return len_mirge;
    }
}

/*
void one(int data[], int max) {
    for (int i = 0; i < max; i++) {
        std::cout << data[i] << ' ';
        *&data[i] = 5 - i;
    }
}*/

int main()
{   
    int menu;
    std::cout << "====================================================== MENU ======================================================\n";
    std::cout << "Enter menu num: ";
    std::cin >> menu;
    std::cout << "\n===================================================== TASK " 
              << menu 
              << " ===================================================== \n";
    switch (menu) {
    case 1:
        std::cout << "Bubble sort\n";
        break;

    case 2:
        std::cout << "Counting sort\n";
        break;

    case 3:
        std::cout << "Merge sort\n";
        break;
    }

    // start read array
    const int max_size = 1000;
    int data[max_size];
    std::string s = "";
    int ctn = 0;

    // input nums
    std::cout << "To end input enter '-'\nData[" << ctn << "]: ";
    std::cin >> s;
    while (s != "-") {
        try {
            data[ctn] = std::stoi(s);
        }
        catch (std::invalid_argument e) {
            data[ctn] = (int)s[0];
        }
        ctn++;

        std::cout << "Data[" << ctn << "]: ";
        std::cin >> s;
    }
    // stop read array

    switch (menu) {
    case 1 :
         bubbles(data, ctn);
         break; 

    case 2:
        counting_sort(data, ctn);
        break;
    case 3:
        int ansver_arr[1000];
        int ansver_len = merge_sort(data, 0, ctn, ansver_arr);
        std::cout << "\nAnswer: ";
        for (int i = 0; i < ansver_len; i++) {
            std::cout << ansver_arr[i] << ' ';
        }
        std::cout << "\n";
        break;
    }

    return 0;
}
