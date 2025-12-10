#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#pragma region Task1

double* allocateMemory(int size) {
    return new double[size];
}

void fillArray(double* arr, int size) {
    cout << "Введите " << size << " элементов массива (типа double):\n";
    for (int i = 0; i < size; i++) {
        cout << "Элемент [" << i << "]: ";
        cin >> arr[i];
    }
}

void printArray(double* arr, int size) {
    cout << "Содержимое массива:\n";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void freeMemory(double* arr) {
    delete[] arr;
    cout << "Память освобождена.\n";
}

#pragma endregion

#pragma region Task2

void swapEvenOdd(int* arr, int size) {
    for (int i = 0; i < size - 1; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

void printIntArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

#pragma endregion

#pragma region Task3

int** allocateMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % 41 + 10;  // 10-50
        }
    }
}

void printMatrix(int** matrix, int rows, int cols) {
    cout << "Матрица " << rows << "x" << cols << ":\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    cout << "Память матрицы освобождена.\n";
}

#pragma endregion

#pragma region Maim

int main() {
    srand(time(0)); // для случайных чисел в задании 3

    int choice;

    do {
        cout << "\n=== МЕНЮ ===\n";
        cout << "1. Работа с массивом double (создание, заполнение, вывод)\n";
        cout << "2. Обмен четных и нечетных ячеек в массиве int\n";
        cout << "3. Двумерный динамический массив со случайными числами\n";
        cout << "0. Выход\n";
        cout << "Выберите задание: ";
        cin >> choice;

        if (choice == 1) {
            // ЗАДАНИЕ 1
            char innerChoice;
            do {
                int size;
                cout << "\n=== ЗАДАНИЕ 1 ===\n";
                cout << "Введите размер массива: ";
                cin >> size;

                double* arr = allocateMemory(size);
                fillArray(arr, size);
                printArray(arr, size);
                freeMemory(arr);

                cout << "\nХотите создать новый массив? (y/n): ";
                cin >> innerChoice;
            } while (innerChoice == 'y' || innerChoice == 'Y');
        }
        else if (choice == 2) {
            // ЗАДАНИЕ 2
            cout << "\n=== ЗАДАНИЕ 2 ===\n";

            // Создаем массив из 12 элементов
            int* arr = new int[12];

            // Заполняем значениями 1..12
            cout << "Исходный массив (12 элементов):\n";
            for (int i = 0; i < 12; i++) {
                arr[i] = i + 1;
            }
            printIntArray(arr, 12);

            // Меняем четные и нечетные
            swapEvenOdd(arr, 12);

            cout << "После обмена четных и нечетных ячеек:\n";
            printIntArray(arr, 12);

            delete[] arr;
            cout << "Память массива освобождена.\n";
        }
        else if (choice == 3) {
            // ЗАДАНИЕ 3
            cout << "\n=== ЗАДАНИЕ 3 ===\n";

            int rows, cols;
            cout << "Введите количество строк: ";
            cin >> rows;
            cout << "Введите количество столбцов: ";
            cin >> cols;

            int** matrix = allocateMatrix(rows, cols);
            fillMatrix(matrix, rows, cols);
            printMatrix(matrix, rows, cols);
            freeMatrix(matrix, rows);
        }
        else if (choice == 0) {
            cout << "Выход из программы...\n";
        }
        else {
            cout << "Неверный выбор! Попробуйте снова.\n";
        }

    } while (choice != 0);

    return 0;
}

#pragma endregion
