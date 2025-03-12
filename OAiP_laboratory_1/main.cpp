#include <iostream>
#include <fstream>

#include "train.h"

void firstItem(Train*& train) {
    std::cout << "Выберите пункт из списка:\n";

    std::cout << "1. Ввести из консоли.\n";
    std::cout << "2. Ввести из файла.\n";

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
        consoleInput(train);
    }
    else if(choice == 2) {
        std::cout << "Введите путь к файлу: ";

        std::string s;
        std::cin >> s;

        std::fstream file(s, std::ios::in);

        if(!file) {
            std::cout << "Ошибка! Не удалось открыть файл.\n";
            return;
        }

        fileInput(train, file);
        file.close();
    }
    else {
        std::cout << "Ошибка! Выбранного пункта не существует.\n";
    }
}

void secondItem(Train*& train) {
    std::cout << "Выберите пункт из списка:\n";

    std::cout << "1. Вывести в консоль.\n";
    std::cout << "2. Вывести в файл.\n";

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
        consoleOutput(train);
    }
    else if(choice == 2) {
        std::cout << "Введите путь к файлу (если файла с указанным именем не существует, то файл будет создан): ";

        std::string s;
        std::cin >> s;

        std::fstream file(s, std::ios::app);

        if(!file) {
            std::cout << "Ошибка! Не удалось открыть/создать файл.\n";
            return;
        }

        fileOutput(train, file);
        file.close();
    }
    else {
        std::cout << "Ошибка! Выбранного пункта не существует.\n";
    }
}

int main() {
    Train* train = new Train[10];

    bool running = true;
    while(running) {
        std::cout << "Выберите пункт из списка:\n";

        std::cout << "1. Ввести информацию о поездах.\n";
        std::cout << "2. Вывести информацию о поездах.\n";
        std::cout << "3. Упорядочить информацию о поздах.\n";
        std::cout << "4. Изменить информацию о поздах.\n";
        std::cout << "5. Выход.\n";

        std::cout << "Ваш выбор: ";

        int choice;
        std::cin >> choice;

        if(std::cin.fail() || std::cin.peek() != '\n') {
            std::cout << "Ошибка! Введённое значение не является числом.\n";

            std::cin.clear();
            std::cin.ignore(100000, '\n');

            continue;
        }

        switch (choice) {
            case 1:
                firstItem(train);
                break;

            case 2:
                secondItem(train);
                break;

            case 3:
                sorting(train);
                break;

            case 4:
                change(train);
                break;

            case 5:
                running = false;
                break;

            default:
                std::cout << "Ошибка! Выбранного пункта не существует.\n";
        }
    }

    delete[] train;
    return 0;
}