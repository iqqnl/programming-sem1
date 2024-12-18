#include <iostream>
#include <cmath>

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
				std::swap(ar[j], ar[j - 1]);
				f = true;
			}
		}
		if (!f) return;
	}
}

bool DeegreeOfTwo(int digit)
{
	int initValue{ 1 };
	while (initValue < digit)
		initValue *= 2;
	return (digit == initValue) ? true : false;
}


void ShowingArrayWithRounding(float* arr, int SIZE, bool f)
{
	for (int i{}; i < SIZE / 2; i++)
	{
		if (f)
			cout << int(arr[i]) << ' ';
		else
		{
			arr[i] = round(arr[i] * 100.0) / 100.0;
			cout << arr[i] << ' ';
		}
	}
	std::cout << endl;
}


void RedistributionArrays(float* arr1, float* arr2, int SIZE)
{
	for (int i{ 0 }; i < SIZE; ++i)
	{
		if (arr1[i] == 0)
		{
			for (int j{ i + 1 }; j < SIZE; ++j)
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
}


void ShowArray(float* arr, int SIZE)
{
	for (int i{}; i < SIZE; i++)
	{
		cout << arr[i];
		if (i + 1 != SIZE)
		{
			if (arr[i + 1] != 0) cout << ' ';
			else break;
		}
	}
	cout << endl;
}


void ExchangingValues1(float* arr1, float* arr2)
{
	int k = 15;
	for (int i{ 0 }; i < 15; i++)
	{
		if (arr1[i] > 0)
		{
			arr2[k] = arr1[i];
			arr1[i] = 0;
			k++;
		}
	}
}

void ExchangingValues2(float* arr1, float* arr2)
{
	int k = 15;
	for (int i{ 0 }; i < 15; i++)
	{
		if (arr1[i] < 0)
		{
			arr2[k] = arr1[i];
			arr1[i] = 0;
			k++;
		}
	}
}


void FiveMin(float* arr, int SIZE)
{
	for (int i{ 0 }; i < 3; ++i)
	{
		float min = 99999999.0;
		for (int j{ 0 }; j < 5; j++)
		{
			if (arr[i * 5 + j] < min)
			{
				min = arr[i * 5 + j];
			}
		}
		cout << "Минимум для " << i + 1 << " пятёрки = " << min << endl;
	}
}


void СountDegreeTwo(float* arr, int SIZE)
{
	bool flag = false, flag2 = false;
	for (int i{ 0 }; i < SIZE / 2 - 1; ++i)
	{
		if (DeegreeOfTwo(arr[i]) && DeegreeOfTwo(arr[i + 1]) && arr[i] * 2 == arr[i + 1])
		{
			for (int j = i + 1; j < SIZE / 2 - 1; ++j)
			{
				if (DeegreeOfTwo(arr[j]) == false)
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
}


int CountRepeatedNumbers(float* arr, int SIZE)
{
	int countRepeatedNumbers{};
	for (int i{ 1 }; i < SIZE / 2 - 1; i++)
	{
		if (arr[i] == arr[i - 1] && arr[i] != arr[i + 1])
		{
			countRepeatedNumbers++;
		}
	}

	if (countRepeatedNumbers == 0 && arr[0] == arr[1])
		countRepeatedNumbers++;
	return countRepeatedNumbers;
}

float Min(float a, float b)
{
	return (a <= b) ? a : b;
}

float Max(float a, float b)
{
	return (a >= b) ? a : b;
}

// определение значения F
void DeterminingValueF(float a, float b, float c, float* arr, float x1, float x2, float step)
{
	float F{};
	float intermediateX = x1;	
	int k = 0;
	while (intermediateX <= x2)
	{
		if (intermediateX < 0 && b != 0)
			F = a * intermediateX * intermediateX + b;
		else if (intermediateX > 0 && b == 0)
			F = (intermediateX - a) / (intermediateX - c);
		else
			F = intermediateX / c;

		arr[k] = F;

		intermediateX += step;
		k++;
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");

	const int SIZE = 30;
	float arr1[SIZE]{}, arr2[SIZE]{};
	float x1{}, x2{}, intermediateX{};
	float a{}, b{}, c{};
	std::cout << "Введите X1: ";
	std::cin >> x1;
	std::cout << "Введите X2: ";
	std::cin >> x2;
	std::cout << "Введите a: ";
	std::cin >> a;
	std::cout << "Введите b: ";
	std::cin >> b;
	std::cout << "Введите c: ";
	std::cin >> c;

	if (x1 > x2) swap(x1, x2);

	float step = (x2 - x1) / 14;
	
	// правда - тип int
	// ложь - тип float
	bool f{};
	f = (((int(a) | int(b)) & (int(a) | int(c))) == 0) ? true : f = false;


//	cout << Max(x1, x2);

	float F{};

	DeterminingValueF(a, b, c, arr1, x1, x2, step);
	DeterminingValueF(a, b, c, arr2, -x2, -x1, step);
	

	ShowingArrayWithRounding(arr1, SIZE, f);
	ShowingArrayWithRounding(arr2, SIZE, f);

	FiveMin(arr1, SIZE);

	cout << "Отсортированный массив: ";
	sortBuble(arr1, SIZE / 2);
	ShowArray(arr1, SIZE / 2);


	

	cout << endl;
	cout << "Количество повторяющих чисел в массиве = " << CountRepeatedNumbers(arr1, SIZE) << endl;


	СountDegreeTwo(arr1, SIZE);


//	ShowArray(arr1, SIZE);
//	ShowArray(arr1, SIZE);

	ExchangingValues1(arr1, arr2);
	ExchangingValues2(arr2, arr1);




	RedistributionArrays(arr1, arr2, SIZE);
	RedistributionArrays(arr2, arr1, SIZE);

	ShowArray(arr1, SIZE);
	ShowArray(arr2, SIZE);
	

	return 0;
}