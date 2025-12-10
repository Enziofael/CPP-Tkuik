#include <iostream>
using namespace std;

int main() {
	int m, n;
	cout << "\nЛабораторная работа 3" << endl;

#pragma region Task1
	cout << "\n\nЗадание 1" << endl;

	cout << "Введите количество строк (m): ";
	cin >> m;
	cout << "Введите количество столбцов (n): ";
	cin >> n;

	int** A = new int* [m];
	for (int i = 0; i < m; i++) {
		A[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> A[i][j];
		}
	}

	int* B = new int[m];

	for (int i = 0; i < m; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (A[i][j] % 2 == 0) {
				count++;
			}
		}
		B[i] = count;
	}

	int min_count = B[0];
	int min_row = 0;
	for (int i = 1; i < m; i++) {
		if (B[i] < min_count) {
			min_count = B[i];
			min_row = i;
		}
	}

	cout << "Массив B (количество чётных в каждой строке):\n";
	for (int i = 0; i < m; i++) {
		cout << B[i] << " ";
	}
	cout << "\nНомер строки с минимальным количеством чётных: " << min_row + 1 << endl;

	for (int i = 0; i < m; i++) {
		delete[] A[i];
	}
	delete[] A;
	delete[] B;
#pragma endregion

#pragma region Task2
	cout << "\n\nЗадание 2" << endl;

	cout << "Введите количество строк: ";
	cin >> m;
	cout << "Введите количество столбцов: ";
	cin >> n;

	int** matrix = new int* [m];
	for (int i = 0; i < m; i++) {
		matrix[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> matrix[i][j];
		}
	}

	bool found = false;
	for (int i = 0; i < m; i++) {
		bool has_zero = false;

		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == 0) {
				has_zero = true;
				break;
			}
		}

		if (!has_zero) {
			long long product = 1;
			for (int j = 0; j < n; j++) {
				product *= matrix[i][j];
			}
			cout << "Строка " << i + 1 << ": произведение = " << product << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Строк без нулей нет.\n";
	}


	for (int i = 0; i < m; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
#pragma endregion

#pragma region Task3
	cout << "\n\nЗадание 3" << endl;

	cout << "Введите размер матрицы (n): ";
	cin >> n;

	int** A = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> A[i][j];
		}
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A[i][i];
	}

	double average = sum / n;
	cout << "Среднее арифметическое элементов главной диагонали: " << average << endl;

	for (int i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[] A;

#pragma endregion

#pragma region Task4
	cout << "\n\nЗадание 4" << endl;

	cout << "Введите размер матрицы (n): ";
	cin >> n;

	int** A = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> A[i][j];
		}
	}

	bool found = false;
	for (int i = 0; i < n; i++) {
		bool increasing = true;
		for (int j = 1; j < n; j++) {
			if (A[i][j] <= A[i][j - 1]) {
				increasing = false;
				break;
			}
		}
		if (increasing) {
			cout << "Строка " << i + 1 << " образует строго возрастающую последовательность.\n";
			found = true;
		}
	}

	if (!found) {
		cout << "Таких строк нет.\n";
	}

	for (int i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[] A;

#pragma endregion

#pragma region Task5
	cout << "\n\nЗадание 5" << endl;

	cout << "Введите размер матрицы (n): ";
	cin >> n;

	int** A = new int* [n];
	for (int i = 0; i < n; i++) {
		A[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A[i][j];
		}
	}

	long long product = 1;
	bool found_even = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) { // выше главной диагонали (j > i)
				if (A[i][j] % 2 == 0) {
					product *= A[i][j];
					found_even = true;
				}
			}
		}
	}

	if (found_even) {
		cout << "Произведение четных элементов выше главной диагонали: " << product << endl;
	}
	else {
		cout << "Четных элементов выше главной диагонали нет.\n";
	}

	for (int i = 0; i < n; i++) {
		delete[] A[i];
	}
	delete[] A;

#pragma endregion

	cin >> n;
	cout << "\nЗавершаем\n";
	return 0;
}