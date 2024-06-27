#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <regex>
#include <chrono>
using namespace std;
regex checknum("([1-9]+)([0-9]*)");
struct person { // структура, содержащая информацию о человеке
	string lastname; // фамилия
	string firstname; // имя
	string patronimic; // отчество
	int tel; // телефон
};

int currentsize = 0; // размер хэш-таблицы

bool operator == (person pers1, person pers2) { // перегрузка оператора сравнения структур
	return (pers1.lastname == pers2.lastname && pers1.firstname == pers2.firstname && pers1.patronimic == pers2.patronimic && pers1.tel == pers2.tel);
}

class Hashtable { // класс хэш-функции
private:
	vector<vector<person>> table; // хэш-таблица

public:
	Hashtable() { // конструктор хэш-таблицы
		table.resize(currentsize);
	}

	int hashfunc(int copynum) { // функция для подсчета хэша
		int sum = 0;
		while (copynum) {
			sum += (copynum % 10);
			copynum /= 10;
		}
		return sum % currentsize;
	}

	void add(person pers) { // функция для добавления информации
		int index = hashfunc(pers.tel);
		table[index].push_back(pers);
	}

	void del(int te) { // функция для удаления информации
		int index = hashfunc(te);
		if (table[index].empty()) {
			cout << "Такого человека нет в списке\n";
		}
		else {
			bool t = false;
			for (int i = 0; i < table[index].size(); i++) {
				if (te == table[index][i].tel) {
					table[index].erase(table[index].begin() + i);
					t = true;
					break;
				}
			}
			if (!t) {
				cout << "Такого человека нет в списке\n";
			}
		}
	}

	void search(int te) { // функция для поиска информации
		int index = hashfunc(te);
		if (table[index].empty()) {
			cout << "Такого человека нет в списке\n";
		}
		else {
			bool t = false;
			for (int i = 0; i < table[index].size(); i++) {
				if (te == table[index][i].tel) {
					cout << "Информация найдена\n" << "Она находится в ячейке с индексом " << index << " в " << i + 1 << " месте этой ячейки\n";
					t = true;
					break;
				}
			}
			if (!t) {
				cout << "Такого человека нет в списке\n";
			}
		}
	}

	void output() { // функция для вывода элементов хэш-таблицы
		for (int i = 0; i < table.size(); i++) {
			cout << "Ячейка с индексом " << i << '\n';
			if (table[i].empty()) {
				cout << "Пусто\n";
				cout << '\n';
			}
			else {
				for (int j = 0; j < table[i].size(); j++) {
					cout << "Фамилия: " << table[i][j].lastname << '\n';
					cout << "Имя: " << table[i][j].firstname << '\n';
					cout << "Отчество: " << table[i][j].patronimic << '\n';
					cout << "Телефон: " << table[i][j].tel << '\n';
					cout << '\n';
				}
			}
		}
	}

};

bool checkfio(string f) {
	bool t = false;
	if (f == "" || f == "\n") {
		return 0;
	}
	for (int i = 0; i < f.length(); i++) {
		if (i == 0) {
			if ((f[0] >= 'A' && f[0] <= 'Z') || (f[0] >= 'А' && f[0] <= 'Я')) {
				t = true;
				continue;
			}
			else {
				return 0;
			}
		}
		else if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= 'А' && f[i] <= 'Я') && t) {
			if (f[i - 1] == '-') {
				continue;
			}
			else {
				return 0;
			}
		}
		else if ((f[i] >= 'a' && f[i] <= 'z') || (f[i] >= 'а' && f[i] <= 'я')) {
			if (f[i - 1] == '-') {
				return 0;
			}
			continue;
		}
		else if (f[i] == '-') {
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int choice;
	string b;
	cout << "Введите размер таблицы\n";
	getline(cin, b);
	while (!regex_match(b, checknum)) {
		cout << "Некорректный ввод\n";
		getline(cin, b);
	}
	currentsize = stoi(b);
	Hashtable table;
	for (;;)
	{
		cout << "1 - вывод хеш-таблицы на экран\n";
		cout << "2 - добавить элемент\n";
		cout << "3 - удалить элемент\n";
		cout << "4 - найти элемент по ключу\n";
		cout << "0 - выход\n";
		cout << "сделайте выбор\n";
		getline(cin, b);
		while (b.length() != 1) {
			cout << "Некорректный ввод\n";
			getline(cin, b);
		}
		choice = b[0];
		switch (choice)
		{
		case '0':  exit(0);
		case '1': {
			table.output();
			break;
		}
		case '2': {
			person buf;
			cout << "введите Фамилию\n";
			getline(cin, b);
			while (!checkfio(b)) {
				cout << "Некорректный ввод\n";
				getline(cin, b);
			}
			buf.lastname = b;
			cout << "введите имя\n";
			getline(cin, b);
			while (!checkfio(b)) {
				cout << "Некорректный ввод\n";
				getline(cin, b);
			}
			buf.firstname = b;
			cout << "введите отчество\n";
			getline(cin, b);
			while (!checkfio(b)) {
				cout << "Некорректный ввод\n";
				getline(cin, b);
			}
			buf.patronimic = b;
			cout << "введите номер телефона\n";
			getline(cin, b);
			while (!regex_match(b, checknum)) {
				cout << "Некорректный ввод\n";
				getline(cin, b);
			}
			buf.tel = stoi(b);
			table.add(buf);
			break;
		}
		case '3': {
			cout << "введите номер телефона\n";
			getline(cin, b);
			while (!regex_match(b, checknum)) {
				cout << "Некорректный ввод\n";
				getline(cin, b);
			}
			table.del(stoi(b));
			break;
		}
		case '4': {
			cout << "введите номер телефона\n";
			getline(cin, b);
			while (!regex_match(b, checknum)) {
				cout << "Некорректный ввод\n";
				getline(cin, b);
			}
			auto start = chrono::high_resolution_clock::now();
			table.search(stoi(b));
			auto end = chrono::high_resolution_clock::now();
			auto time = chrono::duration_cast<std::chrono::microseconds>(end - start);
			cout << "Время поиска " << time.count() << "мкс\n";
			break;
		}
		default:  cout << "\nВведена неверная команда!\n";
		}
	}
	return 0;
}