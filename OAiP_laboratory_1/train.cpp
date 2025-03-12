#include "train.h"

#include <iostream>
#include <fstream>
#include <string>

void consoleInput(Train*& train) {
    for(int i = 0; i < 10; i++) {
        std::cout << "\nВведите название пункта назначения: ";
        std::cin >> train[i].name;

        std::cout << "Введите номер поезда: ";
        std::cin >> train[i].number;

        if(std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка! Введённое значение не является числом.\n";

            std::cin.clear();
            std::cin.ignore(100000, '\n');

            i--;
            continue;
        }

        std::cout << "Введите время отправления (в формате hh:mm): ";
        std::cin >> train[i].time;
    }
}

void fileInput(Train*& train, std::fstream& file) {
    for(int i = 0; i < 10; i++) {
        file >> train[i].name;
        file >> train[i].number;
        file >> train[i].time;
    }
}

void sorting(Train*& train) {
    for(int i = 0; i < 10; i++) {
        for(int j = i + 1; j < 10; j++) {
            if(train[i].name > train[j].name) {
                Train temporary = train[j];
                train[j] = train[i];
                train[i] = temporary;
            }
        }
    }
}

void change(Train*& train) {
    std::cout << "Введите номер изменяемого элемента: ";

    int number;
    std::cin >> number;

    if(std::cin.fail() || std::cin.peek() != '\n') {
        std::cout << "Ошибка! Введённое значение не является числом.\n";

        std::cin.clear();
        std::cin.ignore(100000, '\n');

        return;
    }

    if(number < 1 || number > 10) {
        std::cout << "Ошибка! Элемента с выбранным номером не сушествует.\n";
        return ;
    }

    std::cout << "Выберите изменяемый параметр из списка:\n";

    std::cout << "1. Название пункта назначения.\n";
    std::cout << "2. Номер поезда.\n";
    std::cout << "3. Время отправления.\n";

    std::cout << "Ваш выбор: ";

    int choice;
    std::cin >> choice;

    if(std::cin.fail() || std::cin.peek() != '\n') {
        std::cout << "Ошибка! Введённое значение не является числом.\n";

        std::cin.clear();
        std::cin.ignore(100000, '\n');

        return;
    }

    if(choice == 1) {
        std::cout << "Введите новое название пункта назначения: ";

        std::string s;
        std::cin >> s;

        train[number - 1].name = s;
    }
    else if(choice == 2) {
        std::cout << "Введите новый номер поезда: ";

        int x;
        std::cin >> x;

        if(std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка! Введённое значение не является числом.\n";

            std::cin.clear();
            std::cin.ignore(100000, '\n');

            return;
        }

        train[number - 1].number = x;
    }
    else if(choice == 3) {
        std::cout << "Введите новое время отправления (в формате hh:mm): ";

        std::string t;
        std::cin >> t;

        train[number - 1].time = t;
    }
    else {
        std::cout << "Ошибка! Выбранного параметра не существует.\n";
    }
}

void consoleOutput(Train*& train) {
    std::cout << "Введите пункт назначения для вывода информации о направляющихся в него поездах (для вывода информации о всех поездах укажите символ *): ";

    std::string s;
    std::cin >> s;

    bool flag = false;
    for(int i = 0; i < 10; i++) {
        if(s == "*" || train[i].name == s) {
            flag = true;
            std::cout << train[i].name << " ";
            std::cout << train[i].number << " ";
            std::cout << train[i].time << "\n";
        }
    }

    if(!flag) {
        std::cout << "Поездов с заданным пунктом назначения нет\n";
    }
}

void fileOutput(Train*& train, std::fstream& file) {
    std::cout << "Введите пункт назначения для вывода информации о направляющихся в него поездах (для вывода информации о всех поездах укажите символ *): ";

    std::string s;
    std::cin >> s;

    bool flag = false;
    for(int i = 0; i < 10; i++) {
        if(s == "*" || train[i].name == s) {
            flag = true;
            file << train[i].name << " ";
            file << train[i].number << " ";
            file << train[i].time << "\n";
        }
    }

    if(!flag) {
        file << "Поездов с заданным пунктом назначения нет\n";
    }
}
