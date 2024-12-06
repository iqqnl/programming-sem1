#include <iostream>
#include <cmath>
#include <windows.h>
using namespace std;

void sortBuble(float* ar, int size) {
	bool f{};
	for (int i = 0; i < size - 1; i++)
	{
		f = false;
		for (int j = size - 1; j > i; j--)
		{
			if (ar[j] < ar[j - 1])
			{
				swap(ar[j], ar[j - 1]);
				f = true;
			}
		}
		if (!f) return;
	}
}

bool DeegreeOfTwo(int digit)
{
	int initValue = 1 ;
	while (initValue < digit)
		initValue *= 2;
	return (digit == initValue) ? true : false;
}

int main(int argc, char* argv[]) {
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0) {
        isHuman = true;
    }
	
SetConsoleCP(1251);
SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");

	const int SIZE = 30;
	float arr1[SIZE]{}, arr2[SIZE]{};
	float x1{}, x2{}, intermediateX{};
	float a{}, b{}, c{};
	cout << "Введите X1: ";
	cin >> x1;
	cout << "Введите X2: ";
	cin >> x2;
	cout << "Введите a: ";
	cin >> a;
	cout << "Введите b: ";
	cin >> b;
	cout << "Введите c: ";
	cin >> c;

	if (x1 > x2) swap(x1, x2);

	float step = (x2 - x1) / 14;
	intermediateX = x1;

	// правда - тип int
	// ложь - тип float
	bool f{};
	f = (((int(a) | int(b)) & (int(a) | int(c))) == 0) ? true : f = false;

	float F{};

	int k = 0;
	while (intermediateX <= x2)
	{
		if (intermediateX < 0 && b != 0)
			F = a * intermediateX * intermediateX + b;
		else if (intermediateX > 0 && b == 0)
			F = (intermediateX - a) / (intermediateX - c);
		else
			F = intermediateX / c;

		arr1[k] = F;

		intermediateX += step;
		k++;
	}


	k = 0;
	intermediateX = x2 * (-1);
	while (intermediateX <= x1 * (-1))
	{
		if (intermediateX < 0 && b != 0)
			F = a * intermediateX * intermediateX + b;
		else if (intermediateX > 0 && b == 0)
			F = (intermediateX - a) / (intermediateX - c);
		else
			F = intermediateX / c;

		arr2[k] = F;

		intermediateX += step;
		k++;
	}


	for (int i = 0; i < SIZE / 2; i++)
	{
		if (f)
			cout << int(arr1[i]) << ' ';
		else
		{
			arr1[i] = round(arr1[i] * 100.0) / 100.0;
			cout << arr1[i] << ' ';
		}
	}
	cout << endl;

	for (int i = 0; i < SIZE / 2; i++)
	{
		if (f)
			cout << int(arr2[i]) << ' ';
		else
		{
			arr2[i] = round(arr2[i] * 100.0) / 100.0;
			cout << arr2[i] << ' ';
		}
	}
	cout << endl;

	for (int i = 0 ; i < 3; ++i)
	{
		float min = 99999999.0;
		for (int j = 0; j < 5; j++)
		{
			if (arr1[i * 5 + j] < min)
			{
				min = arr1[i * 5 + j];
			}
		}
		cout << "Минимум для " << i + 1 << " пятёрки = " << min << endl;
	}

	cout << "Отсортированный массив: ";
	sortBuble(arr1, SIZE / 2);
	for (int i = 0; i < SIZE / 2; i++)
	{
		cout << arr1[i] << ' ';
	}
	cout << endl;


	int countRepeatedNumbers{};
	for (int i = 1 ; i < SIZE / 2 - 1; i++)
	{
		if (arr1[i] == arr1[i - 1] && arr1[i] != arr1[i + 1])
		{
			countRepeatedNumbers++;
		}
	}

	if (countRepeatedNumbers == 0 && arr1[0] == arr1[1])
		countRepeatedNumbers++;

	cout << endl;
	cout << "Количество повторяющих чисел в массиве = " << countRepeatedNumbers << endl;



	bool flag = false, flag2 = false;
	for (int i = 0 ; i < SIZE / 2 - 1; ++i)
	{
		if (DeegreeOfTwo(arr1[i]) && DeegreeOfTwo(arr1[i + 1]) && arr1[i] * 2 == arr1[i + 1])
		{
			for (int j = i + 1; j < SIZE / 2 - 1; ++j)
			{
				if (DeegreeOfTwo(arr1[j]) == false)
				{
					flag = false;
					break;
				}
			}
			if (flag)
			{
				cout << "Степень двойки начинается с " << i << " элемента" << endl;
				flag2 = true;
				break;
			}
		}
	}
	if (!flag)
	{
		cout << "В данном массиве нет степеней двойки " << -1 << endl;
	}



	k = 15;
	for (int i = 0 ; i < 15; i++)
	{
		if (arr1[i] > 0)
		{
			arr2[k] = arr1[i];
			arr1[i] = 0;
			k++;
		}
	}

	k = 15;
	for (int i = 0; i < 15; i++)
	{
		if (arr2[i] < 0)
		{
			arr1[k] = arr2[i];
			arr2[i] = 0;
			k++;
		}
	}

	for (int i = 0; i < SIZE; ++i)
	{
		if (arr1[i] == 0)
		{
			for (int j = i + 1 ; j < SIZE; ++j)
			{
				if (arr1[j] != 0)
				{
					arr1[i] = arr1[j];
					arr1[j] = 0;
					break;
				}
			}
		}
	}

	for (int i = 0 ; i < SIZE; ++i)
	{
		if (arr2[i] == 0)
		{
			for (int j = 29 ; j > i; --j)
			{
				if (arr2[j] != 0)
				{
					arr2[i] = arr2[j];
					arr2[j] = 0;
					break;
				}
			}
		}
	}

	for (int i = 0 ; i < SIZE; i++)
	{
		if (arr1[i] != 0)
		{
			cout << arr1[i];
			if (i != SIZE - 1)
			{
				cout << ' ';
			}
		}
	}
	cout << endl;

	for (int i = 0; i < SIZE; i++)
	{
		if (arr2[i] != 0)
		{
			cout << arr2[i];
			if (i != SIZE - 1)
			{
				cout << ' ';
			}
		}
	}
	cout << endl;

	return 0;
}