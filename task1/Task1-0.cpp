#include <iostream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru_RU");

    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0) {
        isHuman = true;
    }

    int num, sum = 0, count = 0;

    if (isHuman) {
        cout << "Введите целые числа (введите 0 для завершения ввода):" << endl;
    }

    while (cin >> num && num != 0) {
        sum += num;
        count++;
    }

    if (count == 0) {
        if (isHuman) {
            cout << "Последовательность не введена." << endl;
        }
    } else {
        double average = static_cast<double>(sum) / count;
        if (isHuman) {
            cout << "Среднее арифметическое: " << average << endl;
        } else {
            cout << average << endl;
        }
    }

    return 0;
}