#include <iostream>
using namespace std;

void deleteMatrix(int** array, int numberOfRows) {
    if (array == nullptr) {
        return;
    }

	for (int i = 0; i < numberOfRows; i++) {
		delete[] array[i];
	}
	delete[] array;
}

int** createMatrix(int numberOfRows, int numberOfColumns) {
    int** result = new int*[numberOfRows];
    for (int i = 0; i < numberOfRows; i++) {
        result[i] = new int[numberOfColumns];
    }
    return result;
}


void printMatrix(int** array, int numberOfRows, int numberOfColums) {
    if (array == nullptr) {
        return;
    }

	for (int i = 0; i < numberOfRows; i++)  {
		for (int j = 0; j < numberOfColums - 1; j++) {
			cout << array[i][j] << " ";
		}
		cout << array[i][numberOfColums - 1] << endl;
	}
}

int** readMatrix(int numberOfRows, int numberOfColums) {
	int** array = createMatrix(numberOfRows, numberOfColums);

	for (int i = 0; i < numberOfRows; i++)  {
		for (int j = 0; j < numberOfColums; j++) {
			cin >> array[i][j];
		}
	}

	return array;
}

int multiplyRowByColumn(int* row, int** columnOwner, int columnNumber, int rowLength) {
    int result = 0;

    for (int i = 0; i < rowLength; i++) {
        result += row[i] * columnOwner[i][columnNumber];
    }

    return result;
}

int** multipMatrix(int** M1, int M1_numberOfRows, int M1_numberOfColums, int** M2, int M2_numberOfColums) {
    int** result = createMatrix(M1_numberOfRows, M2_numberOfColums);

    for (int i = 0; i < M1_numberOfRows; i++)
    {
        for (int j = 0; j < M2_numberOfColums; j++)
        {
            result[i][j] = multiplyRowByColumn(M1[i], M2, j, M1_numberOfColums);
        }
    }

    return result;
}

int** exponentiation(int** A1, int N,  int x) {
    int** previousPower = nullptr;
    int** currentPower = A1;
    
    for (int i = 0; x > 1 && i < x - 1; i++) {
        previousPower = currentPower;
        currentPower = multipMatrix(A1, N, N, previousPower, N);

        if (i > 0) {
            deleteMatrix(previousPower, N);
        }
    }

    return currentPower;
}

int readInt(const char* message) {
    int number;

    if (message != nullptr) {
        cout << message;
    }
    cin >> number;

    return number;
}

void reassignMatrix(int*** reassignTarget, int** matrixToReassign, int targetRowsNum) {
    deleteMatrix(*reassignTarget, targetRowsNum);
    *reassignTarget = matrixToReassign;
}

int main(int argc, char* argv[]) {
    bool isHuman = false;
    if (argc <= 1 || strcmp(argv[1], "false") != 0) {
    isHuman = true;
	}
    
    setlocale(LC_ALL, "RUS");

    int N = readInt(isHuman ? "Введитн N (число строк): " : nullptr);
    int M = readInt(isHuman ? "Введитн M (число столбцов): " : nullptr);

	int** A1 = readMatrix(N, M);

    int **A2 = nullptr, **multiplicationResult = nullptr, **poweredMatrix = nullptr;
    int K = 0, x = 0;
    while (true) {
        int comm = readInt(isHuman ? "Введите номер команды 0, 1, 2, 3: " : nullptr);
        switch (comm) {
            case 0:
                deleteMatrix(A1, N);
                return 0;
            case 1:
                if (isHuman) 
                {
                    cout << "Матрица А1 " << endl;
                }
                
                printMatrix(A1, N, M);
                break;
            case 2:
                K = readInt(isHuman ? "Введите число К: " : nullptr);
                if (N != K) {
                    break;
                }

                A2 = readMatrix(M, K);
                multiplicationResult = multipMatrix(A1, N, M, A2, K);

                reassignMatrix(&A1, multiplicationResult, N);
                M = K;

                break;
            case 3:
                if (N != M) {
                    cout << "NO" << endl;
                    break;
                }

                x = readInt(isHuman ? "Введите число x: " : nullptr);

                poweredMatrix = exponentiation(A1, N, x);
                
                reassignMatrix(&A1, poweredMatrix, N);

                break;
            default:
                cout << "Введите допустимую команду." << endl;
        }
    }

	return 0;
}

