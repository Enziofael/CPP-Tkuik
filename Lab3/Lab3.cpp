#include <iostream>
using namespace std;

int main() {
	int m, n;
	bool found;
	cout << "\nЛабораторная работа 3" << endl;

#pragma region Task1
	cout << "\n\nЗадание 1" << endl;

	cout << "Введите количество строк (m): ";
	cin >> m;
	cout << "Введите количество столбцов (n): ";
	cin >> n;

	int** A1 = new int* [m];
	for (int i = 0; i < m; i++) {
		A1[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> A1[i][j];
		}
	}

	int* B = new int[m];

	for (int i = 0; i < m; i++) {
		int count = 0;
		for (int j = 0; j < n; j++) {
			if (A1[i][j] % 2 == 0) {
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
		delete[] A1[i];
	}
	delete[] A1;
	delete[] B;
#pragma endregion

#pragma region Task2
	cout << "\n\nЗадание 2" << endl;

	cout << "Введите количество строк: ";
	cin >> m;
	cout << "Введите количество столбцов: ";
	cin >> n;

	int** A2 = new int* [m];
	for (int i = 0; i < m; i++) {
		A2[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> A2[i][j];
		}
	}

	found = false;
	for (int i = 0; i < m; i++) {
		bool has_zero = false;

		for (int j = 0; j < n; j++) {
			if (A2[i][j] == 0) {
				has_zero = true;
				break;
			}
		}

		if (!has_zero) {
			long long product = 1;
			for (int j = 0; j < n; j++) {
				product *= A2[i][j];
			}
			cout << "Строка " << i + 1 << ": произведение = " << product << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "Строк без нулей нет.\n";
	}


	for (int i = 0; i < m; i++) {
		delete[] A2[i];
	}
	delete[] A2;
#pragma endregion

#pragma region Task3
	cout << "\n\nЗадание 3" << endl;

	cout << "Введите размер матрицы (n): ";
	cin >> n;

	int** A3 = new int* [n];
	for (int i = 0; i < n; i++) {
		A3[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> A3[i][j];
		}
	}

	double sum = 0;
	for (int i = 0; i < n; i++) {
		sum += A3[i][i];
	}

	double average = sum / n;
	cout << "Среднее арифметическое элементов главной диагонали: " << average << endl;

	for (int i = 0; i < n; i++) {
		delete[] A3[i];
	}
	delete[] A3;

#pragma endregion

#pragma region Task4
	cout << "\n\nЗадание 4" << endl;

	cout << "Введите размер матрицы (n): ";
	cin >> n;

	int** A4 = new int* [n];
	for (int i = 0; i < n; i++) {
		A4[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << "( " << i << "; " << j << ") = ";
			cin >> A4[i][j];
		}
	}

	found = false;
	for (int i = 0; i < n; i++) {
		bool increasing = true;
		for (int j = 1; j < n; j++) {
			if (A4[i][j] <= A4[i][j - 1]) {
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
		delete[] A4[i];
	}
	delete[] A4;

#pragma endregion

#pragma region Task5
	cout << "\n\nЗадание 5" << endl;

	cout << "Введите размер матрицы (n): ";
	cin >> n;

	int** A5 = new int* [n];
	for (int i = 0; i < n; i++) {
		A5[i] = new int[n];
	}

	cout << "Введите элементы матрицы:\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> A5[i][j];
		}
	}

	long long product = 1;
	bool found_even = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j > i) { // выше главной диагонали (j > i)
				if (A5[i][j] % 2 == 0) {
					product *= A5[i][j];
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
		delete[] A5[i];
	}
	delete[] A5;

#pragma endregion

	cin >> n;
	cout << "\nЗавершаем\n";
	return 0;
}