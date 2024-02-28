#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>
#include <Windows.h>

using namespace std;

// Функция, которая переворачивает слово задом наперед
string reverse(const string& word) {
	string reversedWord = word;
	reverse(reversedWord.begin(), reversedWord.end());
	return reversedWord;
}

bool isRussianVowel(char c) {
	return c == 'а' || c == 'е' || c == 'ё' || c == 'и' || c == 'о' ||
		c == 'у' || c == 'ы' || c == 'э' || c == 'ю' || c == 'я' ||
		c == 'А' || c == 'Е' || c == 'Ё' || c == 'И' || c == 'О' ||
		c == 'У' || c == 'Ы' || c == 'Э' || c == 'Ю' || c == 'Я';
}

bool isRussianConsonant(char c) {
	// Проверка на согласные буквы, если символ не является гласной,
	// и не пробелом (или другими символами, если необходимо)
	return !isRussianVowel(c) && !isspace(c);
}

std::string removeRussianVowels(const std::string& words) {
	std::string result = words;
	result.erase(std::remove_if(result.begin(), result.end(), isRussianVowel), result.end());
	return result;
}

std::string removeRussianConsonants(const std::string& words) {
	std::string result = words;
	result.erase(std::remove_if(result.begin(), result.end(), isRussianConsonant), result.end());
	return result;
}


// Функция, которая перемешивает буквы в слове
string shuffle(const string& word) {
	string shuffledWord = word;
	random_shuffle(shuffledWord.begin(), shuffledWord.end());
	return shuffledWord;
}

int main() {

	SetConsoleCP(1251);
	setlocale(0, "");
	string word;
	cout << "Введите слово: ";
	cin >> word;

	int choice;
	cout << "Выберите действие:\n";
	cout << "1. Слово выводится задом наперед.\n";
	cout << "2. Вывести слово без гласных.\n";
	cout << "3. Вывести слово без согласных.\n";
	cout << "4. Рандомно раскидывать буквы заданного слова.\n";
	cout << "Ваш выбор: ";
	cin >> choice;

	switch (choice) {
	case 1:
		cout << "Результат: " << reverse(word) << endl;
		break;
	case 2:
		cout << "Результат: " << removeRussianVowels(word) << endl;
		break;
	case 3:
		cout << "Результат: " << removeRussianConsonants(word) << endl;
		break;
	case 4:
		srand(time(0)); // Инициализация генератора случайных чисел
		cout << "Результат: " << shuffle(word) << endl;
		break;
	default:
		cout << "Ошибка: Некорректный выбор действия." << endl;
	}

	return 0;
}