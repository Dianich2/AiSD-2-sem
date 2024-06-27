#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include <regex>
#include <chrono>
using namespace std;
regex checknum("([1-9]+)([0-9]*)");
struct person { // ���������, ���������� ���������� � ��������
	string lastname; // �������
	string firstname; // ���
	string patronimic; // ��������
	int tel; // �������
};

int currentsize = 0; // ������ ���-�������

bool operator == (person pers1, person pers2) { // ���������� ��������� ��������� ��������
	return (pers1.lastname == pers2.lastname && pers1.firstname == pers2.firstname && pers1.patronimic == pers2.patronimic && pers1.tel == pers2.tel);
}

class Hashtable { // ����� ���-�������
private:
	vector<vector<person>> table; // ���-�������

public:
	Hashtable() { // ����������� ���-�������
		table.resize(currentsize);
	}

	int hashfunc(int copynum) { // ������� ��� �������� ����
		int sum = 0;
		while (copynum) {
			sum += (copynum % 10);
			copynum /= 10;
		}
		return sum % currentsize;
	}

	void add(person pers) { // ������� ��� ���������� ����������
		int index = hashfunc(pers.tel);
		table[index].push_back(pers);
	}

	void del(int te) { // ������� ��� �������� ����������
		int index = hashfunc(te);
		if (table[index].empty()) {
			cout << "������ �������� ��� � ������\n";
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
				cout << "������ �������� ��� � ������\n";
			}
		}
	}

	void search(int te) { // ������� ��� ������ ����������
		int index = hashfunc(te);
		if (table[index].empty()) {
			cout << "������ �������� ��� � ������\n";
		}
		else {
			bool t = false;
			for (int i = 0; i < table[index].size(); i++) {
				if (te == table[index][i].tel) {
					cout << "���������� �������\n" << "��� ��������� � ������ � �������� " << index << " � " << i + 1 << " ����� ���� ������\n";
					t = true;
					break;
				}
			}
			if (!t) {
				cout << "������ �������� ��� � ������\n";
			}
		}
	}

	void output() { // ������� ��� ������ ��������� ���-�������
		for (int i = 0; i < table.size(); i++) {
			cout << "������ � �������� " << i << '\n';
			if (table[i].empty()) {
				cout << "�����\n";
				cout << '\n';
			}
			else {
				for (int j = 0; j < table[i].size(); j++) {
					cout << "�������: " << table[i][j].lastname << '\n';
					cout << "���: " << table[i][j].firstname << '\n';
					cout << "��������: " << table[i][j].patronimic << '\n';
					cout << "�������: " << table[i][j].tel << '\n';
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
			if ((f[0] >= 'A' && f[0] <= 'Z') || (f[0] >= '�' && f[0] <= '�')) {
				t = true;
				continue;
			}
			else {
				return 0;
			}
		}
		else if ((f[i] >= 'A' && f[i] <= 'Z') || (f[i] >= '�' && f[i] <= '�') && t) {
			if (f[i - 1] == '-') {
				continue;
			}
			else {
				return 0;
			}
		}
		else if ((f[i] >= 'a' && f[i] <= 'z') || (f[i] >= '�' && f[i] <= '�')) {
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
	cout << "������� ������ �������\n";
	getline(cin, b);
	while (!regex_match(b, checknum)) {
		cout << "������������ ����\n";
		getline(cin, b);
	}
	currentsize = stoi(b);
	Hashtable table;
	for (;;)
	{
		cout << "1 - ����� ���-������� �� �����\n";
		cout << "2 - �������� �������\n";
		cout << "3 - ������� �������\n";
		cout << "4 - ����� ������� �� �����\n";
		cout << "0 - �����\n";
		cout << "�������� �����\n";
		getline(cin, b);
		while (b.length() != 1) {
			cout << "������������ ����\n";
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
			cout << "������� �������\n";
			getline(cin, b);
			while (!checkfio(b)) {
				cout << "������������ ����\n";
				getline(cin, b);
			}
			buf.lastname = b;
			cout << "������� ���\n";
			getline(cin, b);
			while (!checkfio(b)) {
				cout << "������������ ����\n";
				getline(cin, b);
			}
			buf.firstname = b;
			cout << "������� ��������\n";
			getline(cin, b);
			while (!checkfio(b)) {
				cout << "������������ ����\n";
				getline(cin, b);
			}
			buf.patronimic = b;
			cout << "������� ����� ��������\n";
			getline(cin, b);
			while (!regex_match(b, checknum)) {
				cout << "������������ ����\n";
				getline(cin, b);
			}
			buf.tel = stoi(b);
			table.add(buf);
			break;
		}
		case '3': {
			cout << "������� ����� ��������\n";
			getline(cin, b);
			while (!regex_match(b, checknum)) {
				cout << "������������ ����\n";
				getline(cin, b);
			}
			table.del(stoi(b));
			break;
		}
		case '4': {
			cout << "������� ����� ��������\n";
			getline(cin, b);
			while (!regex_match(b, checknum)) {
				cout << "������������ ����\n";
				getline(cin, b);
			}
			auto start = chrono::high_resolution_clock::now();
			table.search(stoi(b));
			auto end = chrono::high_resolution_clock::now();
			auto time = chrono::duration_cast<std::chrono::microseconds>(end - start);
			cout << "����� ������ " << time.count() << "���\n";
			break;
		}
		default:  cout << "\n������� �������� �������!\n";
		}
	}
	return 0;
}