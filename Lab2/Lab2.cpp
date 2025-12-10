#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    cout << "\nЛабораторная работа 2" << endl;

#pragma region Task1
    cout << "\n\nЗадание 1" << endl;
    srand(time(0));

    string answers[20] = {
        "Бесспорно",
        "Предрешено",
        "Никаких сомнений",
        "Определённо да",
        "Можешь быть уверен в этом",
        "Мне кажется - да",
        "Вероятнее всего",
        "Хорошие перспективы",
        "Знаки говорят - да",
        "Да",
        "Пока неясно, попробуй снова",
        "Спроси позже",
        "Лучше не рассказывать",
        "Сейчас нельзя предсказать",
        "Сконцентрируйся и спроси опять",
        "Даже не думай",
        "Мой ответ - нет",
        "По моим данным - нет",
        "Перспективы не очень хорошие",
        "Весьма сомнительно"
    };

    string question;
    cout << "Задайте вопрос: ";
    getline(cin, question);

    int index = rand() % 20; // случайное число от 0 до 19
    cout << answers[index];
#pragma endregion

#pragma region Task2
    cout << "\n\nЗадание 2" << endl;

    srand(time(0));
    int secret = rand() % 100 + 1; // от 1 до 100
    int attempts = 5;
    int guess;
    bool win = false;

    cout << "Я загадал число от 1 до 100. У тебя 5 попыток угадать!\n";

    for (int i = 1; i <= attempts; i++) {
        cin >> guess;

        if (guess == secret) {
            cout << "Поздравляю! Ты угадал!\n";
            win = true;
            break;
        }

        int diff = abs(guess - secret);
        if (diff <= 10) {
            cout << "Горячо!\n";
        }
        else if (diff <= 20) {
            cout << "Тепло!\n";
        }
        else {
            cout << "Холодно!\n";
        }
    }

    if (!win) {
        cout << "Ты проиграл! Загаданное число было: " << secret << endl;
    }

    return 0;
#pragma endregion

    cin >> secret;
    cout << "\nЗавершаем\n";
    return 0;
}
