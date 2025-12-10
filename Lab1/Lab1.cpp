#include <iostream>
using namespace std;

int main() {
    cout << "\nЛабораторная работа 1" << endl;

#pragma region Task1
    cout << "\n\nЗадание 1" << endl;
    int N, K;
    cout << "Введите N белочек и K орешков:" << endl;
    cin >> N >> K;
    int result = K / N;
    cout << "У каждой белочки будет орешков: " << result;
#pragma endregion

#pragma region Task2
    cout << "\n\nЗадание 2" << endl;
    cout << "Введите N белочек и K орешков" << endl;
    cin >> N >> K;
    int remainder = K % N;
    cout << "Останется орешков: " << remainder;
#pragma endregion

#pragma region Task3
    cout << "\n\nЗадание 3" << endl;
    cout << "Введите число N" << endl;
    cin >> N;
    int last_digit = N % 10;
    cout << "Последняя цифра числа " << N << " это: " << last_digit << endl;
#pragma endregion

    cin >> N;
    cout << "Завершаем";
    return 0;
}