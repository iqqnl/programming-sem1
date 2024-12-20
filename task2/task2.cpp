#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
using namespace std;

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "ru_RU");

    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0) {
        isHuman = true;
    }

    int N;
    if (isHuman) {
        cout << "Введите количество элементов в возрастающей последовательности: ";
    }
    cin >> N;

    int num;
    int prev = INT_MIN;
    bool isIncreasing = true; 

    if (isHuman) {
        cout << "Введите элементы " << endl;
    }


    for (int i = 0; i < N; ++i) {
        cin >> num;
        if (num <= prev) {
            isIncreasing = false;
        }
        prev = num;
    }

    if (!isIncreasing) {
        cout << "Последовательность не является возрастающей" << endl;
        return 0;
    }


    int b;
    if (isHuman) {
        cout << "Введите число b ";
    }
    cin >> b;

    cout << "Новая последовательность: ";

    bool inserted = false;
    prev = INT_MIN; 

    int i = 0;
    while ( i < N)  {
        cin >> num;

        if (!inserted && b <= num) {
            cout << b << " ";
            inserted = true;
        }
        cout << num << " ";
        prev = num;
        ++i;
    }


    if (!inserted) {
        cout << b;
    }

    cout << endl;
    return 0;
}