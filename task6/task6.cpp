#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

void ShowMatrix(int** matrix, int orderMatrix)
{
    for (int i = 0; i < orderMatrix; ++i)
    {
        for (int j = 0; j < orderMatrix; ++j)
        {
            cout << matrix[i][j] << '\t';
        }
        cout << endl;
    }
}

void FillingMatrixWithZeros(int** matrix, int orderMatrix)
{
    for (int i = 0; i < orderMatrix; ++i)
    {
        for (int j = 0; j < orderMatrix; ++j)
        {
            matrix[i][j] = 0;
        }
    }
}

void FillMatrix(int** matrix, int orderMatrix)
{
    for (int i = 0; i < orderMatrix; i++)
    {
        for (int j = 0; j < orderMatrix; j++)
        {
            cout << "Введите " << i + 1 << " строку, " << j + 1 << " столбец: ";
            cin >> matrix[i][j];
        }
    }
}

void ReplaceElement(int** matrix, int orderMatrix)
{
    int row{}, colomn{}, meaning{};
    cout << "Введите строку, в которой нужно изменить элемент: ";
    cin >> row;
    cout << "Введите столбец, в котором нужно изменить элемент: ";
    cin >> colomn;
    if (row > orderMatrix || colomn > orderMatrix)
    {
        cout << "Вы ввели некорректные данные" << endl;
        return;
    }
    cout << "Введите значение, на которое будет изменен элемент: ";
    cin >> meaning;
    matrix[row - 1][colomn - 1] = meaning;
}

void FillMatrixCWithColumnMins(int** matrixA, int** matrixC, int orderMatrix)
{
    FillingMatrixWithZeros(matrixC, orderMatrix);

    for (int j = 0; j < orderMatrix; ++j)
    {
        int minElement = matrixA[0][j];
        int minRow = 0;

        for (int i = 1; i < orderMatrix; ++i)
        {
            if (matrixA[i][j] < minElement)
            {
                minElement = matrixA[i][j];
                minRow = i;
            }
        }
        matrixC[minRow][j] = minElement;
    }
}

void ReadMatrixFromFile(int** matrix, int orderMatrix, ifstream& inputFile)
{
    for (int i = 0; i < orderMatrix; ++i)
    {
        for (int j = 0; j < orderMatrix; ++j)
        {
            inputFile >> matrix[i][j];
        }
    }
}

void WriteMatrixToFile(int** matrix, int orderMatrix, ofstream& outputFile)
{
    for (int i = 0; i < orderMatrix; ++i)
    {
        for (int j = 0; j < orderMatrix; ++j)
        {
            outputFile << matrix[i][j] << ' ';
        }
        outputFile << endl;
    }
}

void DeleteMatrix(int** matrix, int orderMatrix)
{
    for (int i = 0; i < orderMatrix; ++i)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

void MenuOutput()
{
    cout << "Выберите действия для матриц. По умолчанию матрицы заполнены нулями" << endl;
    cout << "1 - Консольный ввод матриц" << endl;
    cout << "2 - Консольный вывод матриц" << endl;
    cout << "3 - Ввод матриц из файла" << endl;
    cout << "4 - Вывод матриц в файл" << endl;
    cout << "5 - Редактирование матрицы А" << endl;
    cout << "6 - Редактирование матрицы В" << endl;
    cout << "7 - Редактирование матрицы С" << endl;
    cout << "8 - Заполнить матрицу C минимальными элементами столбцов матрицы A" << endl;
    cout << "9 - Выход" << endl;
    cout << "Ваш выбор: ";
}

void CreatingArray(int** matrix, int orderMatrix)
{
    for (int i = 0; i < orderMatrix; ++i)
    {
        matrix[i] = new int[orderMatrix];
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");
    int orderMatrix{}, choice{};

    cout << "Введите порядок для матрицы A, B, C: ";
    cin >> orderMatrix;
    cout << endl;

    int** matrixA = new int* [orderMatrix];
    int** matrixB = new int* [orderMatrix];
    int** matrixC = new int* [orderMatrix];

    CreatingArray(matrixA, orderMatrix);
    CreatingArray(matrixB, orderMatrix);
    CreatingArray(matrixC, orderMatrix);


    FillingMatrixWithZeros(matrixA, orderMatrix);
    FillingMatrixWithZeros(matrixB, orderMatrix);
    FillingMatrixWithZeros(matrixC, orderMatrix);

    do
    {
        MenuOutput();
        cin >> choice;
        cout << endl;

        switch (choice)
        {
        case 1:
            cout << "Введите построчно матрицу A" << endl;
            FillMatrix(matrixA, orderMatrix);
            cout << "Введите построчно матрицу B" << endl;
            FillMatrix(matrixB, orderMatrix);
            cout << "Введите построчно матрицу C" << endl;
            FillMatrix(matrixC, orderMatrix);
            break;

        case 2:
            cout << "Консольный вывод матрицы A" << endl;
            ShowMatrix(matrixA, orderMatrix);
            cout << "Консольный вывод матрицы B" << endl;
            ShowMatrix(matrixB, orderMatrix);
            cout << "Консольный вывод матрицы C" << endl;
            ShowMatrix(matrixC, orderMatrix);
            break;

        case 3:
        {
            ifstream inputFile("input.txt");

            if (!inputFile.is_open())
            {
                cout << "Не удалось открыть файл!" << endl;
                break;
            }

            ReadMatrixFromFile(matrixA, orderMatrix, inputFile);
            ReadMatrixFromFile(matrixB, orderMatrix, inputFile);
            ReadMatrixFromFile(matrixC, orderMatrix, inputFile);

            inputFile.close();
            break;
        }

        case 4:
        {
            ofstream outputFile("output.txt");

            if (!outputFile.is_open())
            {
                cout << "Не удалось открыть файл для записи!" << endl;
                break;
            }

            WriteMatrixToFile(matrixA, orderMatrix, outputFile);
            WriteMatrixToFile(matrixB, orderMatrix, outputFile);
            WriteMatrixToFile(matrixC, orderMatrix, outputFile);

            outputFile.close();
            break;
        }

        case 5:
            ReplaceElement(matrixA, orderMatrix);
            break;

        case 6:
            ReplaceElement(matrixB, orderMatrix);
            break;

        case 7:
            ReplaceElement(matrixC, orderMatrix);
            break;

        case 8:
            FillMatrixCWithColumnMins(matrixA, matrixC, orderMatrix);
            cout << "Матрица C обновлена минимальными элементами из столбцов матрицы A." << endl;
            break;

        case 9:
            cout << "Вы вышли из программы. До свидания!" << endl;
            break;

        default:
            cout << "Вы ввели ошибочное значение, пожалуйста, повторите свой выбор" << endl;
            break;
        }

        cout << endl;
    } while (choice != 9);

    DeleteMatrix(matrixA, orderMatrix);
    DeleteMatrix(matrixB, orderMatrix);
    DeleteMatrix(matrixC, orderMatrix);

    return 0;
}