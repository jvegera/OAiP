#include <chrono>
#include <random>
#include <iostream>
#include <fstream>

struct Person {
	int age;
	std::string name;
	int height;
};

void printArray(Person*& array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i].age << ", " << array[i].height << ", " << array[i].name << "\n";
    }
}

void swap(Person& x, Person& y) {
	Person z = x;

	x = y;
	y = z;
}

// Метод обмена (пузырьковая сортировка)
void bubbleSort(Person*& array, int size) {
	for(int i = 0; i < size; i++) {
		for(int j = size - 1; j > i; j--) {
			if (array[j - 1].age > array[j].age) {
				swap(array[j - 1], array[j]);
			}
		}
	}
}

// Метод вставки
void insertionSort(Person*& array, int size) {
	for(int i = 1; i < size; i++) {
		int j = i;
		while(array[j].height < array[j - 1].height && j > 0) {
			swap(array[j], array[j - 1]);
			j--;
      	}
	}
}

// Метод Хоара (быстрая сортировка)
void quickSort(Person*& array, int left, int right) {
	int i = left, j = right;
	std::string test = array[(left + right) / 2].name;

	do {
		while(array[i].name < test) {
			i++;
		}
		while(array[j].name > test) {
			j--;
		}

		if(i <= j) {
			swap(array[i], array[j]);
			i++, j--;
		}
	} while(i <= j);

	if(i < right) {
		quickSort(array, i, right);
	}
	if(j > left) {
		quickSort(array, left, j);
	}
}

int main() {
	int size = 10;
    Person* array = new Person[size];

	std::fstream file("data.txt", std::ios::in);
	for(int i = 0; i < size; i++) {
		file >> array[i].age >> array[i].height >> array[i].name;
	}

	file.close();

    std::cout << "Массив до сортировки:\n";
	printArray(array, size);

	bool isRunning = true;
	while(isRunning) {
		std::cout << "\nВыберите поле сортировки:\n";

		std::cout << "1. Возраст (пузырьковая сортировка)\n";
		std::cout << "2. Рост (Метод вставки)\n";
		std::cout << "3. Имя (метод хоара (быстрая сортировка))\n";

		std::cout << "Ваш выбор: ";

		int choice;
		std::cin >> choice;

		Person* sortedArray = new Person[size];
		std::copy(array, array + size, sortedArray);

		switch (choice) {
			case 1:
				std::cout << "Выбран метод обмена (пузырьковая сортировка)\n";
				bubbleSort(sortedArray, size);
				break;

			case 2:
				std::cout << "Выбран метод вставки\n";
				insertionSort(sortedArray, size);
				break;

			case 3:
				std::cout << "Выбран метод Хоара (быстрая сортировка)\n";
				quickSort(sortedArray, 0, size - 1);
				break;

			default:
				isRunning = false;
				break;
		}

		std::cout << "Массив после сортировки:\n";
		printArray(sortedArray, size);

		delete[] sortedArray;
	}

    delete[] array;
    return 0;
}