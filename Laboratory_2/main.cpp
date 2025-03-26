#include <chrono>
#include <random>
#include <iostream>

void printArray(int*& array, int size) {
    int elementsToShow = std::min(15, size);

    for (int i = 0; i < std::min(15, size); i++) {
        std::cout << array[i] << " ";
    }

	std::cout << "\n";
}

void swap(int& x, int& y) {
	int z = x;

	x = y;
	y = z;
}

// Метод обмена (пузырьковая сортировка)
void bubbleSort(int*& array, int size) {
	for(int i = 0; i < size; i++) {
		for(int j = size - 1; j > i; j--) {
			if (array[j - 1] > array[j]) {
				swap(array[j - 1], array[j]);
			}
		}
	}
}

// Метод выбора
void selectionSort(int*& array, int size) {
	for(int i = 0; i < size - 1; i++) {
		int k = i;

		for(int j = i + 1; j < size; j++) {
			if(array[j] < array[k]) {
				k = j;
			}
		}

		swap(array[k], array[i]);
	}
}

// Метод вставки
void insertionSort(int*& array, int size) {
	for(int i = 1; i < size; i++) {
		int j = i;
		while(array[j] < array[j - 1] && j > 0) {
			swap(array[j], array[j - 1]);
			j--;
      	}
	}
}

// Метод Шелла
void shellSort(int*& array, int size) {
    for(int gap = size / 2; gap > 0; gap /= 2) {
		bool sorted;
		do
		{
			sorted = false;
			for(int i = 0, j = gap; j < size; i++, j++) {
				if(array[i] > array[j]) {
					swap(array[i], array[j]);
					sorted = true;
				}
			}
		} while(sorted);
	}
}

// Метод Хоара (быстрая сортировка)
void quickSort(int*& array, int left, int right) {
	int i = left, j = right;
	int test = array[(left + right) / 2];

	do {
		while(array[i] < test) {
			i++;
		}
		while(array[j] > test) {
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

void countingSort(int*& array, int size) {
	int* count = new int[size];

	for(int i = 0; i < size; i++) {
		count[array[i]]++;
	}

	int p = 0;
	for(int i = 0; i < size; i++) {
		for(int j = 0; j < count[i]; j++) {
			array[p] = i;
			p++;
		}
	}

	delete[] count;
}

int main() {
    std::mt19937 randomInt(std::chrono::steady_clock::now().time_since_epoch().count());

	int size = 10000;
    int* array = new int[size];
	for(int i = 0; i < size; i++) {
        array[i] = randomInt() % size;
    }

    std::cout << "Массив до сортировки: ";
	printArray(array, size);

	bool isRunning = true;
	while(isRunning) {
		std::cout << "\nВыбора метод сортировки:\n";

		std::cout << "1. Метод обмена (пузырьковая)\n";
		std::cout << "2. Метод выбора\n";
		std::cout << "3. Метод вставки\n";
		std::cout << "4. Метод Шелла\n";
		std::cout << "5. Метод Хоара (быстрая сортировка)\n";
		std::cout << "6. Метод подсчётом (сортировка подсчётом)\n";

		std::cout << "Ваш выбор: ";

		int choice;
		std::cin >> choice;

		int* sortedArray = new int[size];
		std::copy(array, array + size, sortedArray);

		auto start = std::chrono::high_resolution_clock::now();
		switch (choice) {
			case 1:
				std::cout << "Выбран метод обмена (пузырьковая сортировка)\n";
				bubbleSort(sortedArray, size);
				break;

			case 2:
				std::cout << "Выбран метод выбора\n";
				selectionSort(sortedArray, size);
				break;

			case 3:
				std::cout << "Выбран метод вставки\n";
				insertionSort(sortedArray, size);
				break;

			case 4:
				std::cout << "Выбран метод Шелла\n";
				shellSort(sortedArray, size);
				break;

			case 5:
				std::cout << "Выбран метод Хоара (быстрая сортировка)\n";
				quickSort(sortedArray, 0, size - 1);
				break;

			case 6:
				std::cout << "Выбран метод подсчётом (сортировка подсчётом)\n";
				countingSort(sortedArray, size);
				break;

			default:
				isRunning = false;
				break;
		}

		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

		std::cout << "\nВремя сортировки: " << duration.count() << " микросекунд" << "\n";

		std::cout << "Массив после сортировки: ";
		printArray(sortedArray, size);

		delete[] sortedArray;
	}

    delete[] array;
    return 0;
}