#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  unsigned long long int n, l, r;
  unsigned int kol = 0;
  bool t = true;
  vector<int> chisla;
  cout << "������� ������� � ����. �� ��������� �����, � � ���� ���������.\n";
  cout << "������� �������� ��� ����������\n";
  cin >> n;
  if (n == 0) {
    cout << "������������ ����\n";
  }
  else {
    cout << "������ �� ��� ������ ������ ���������\n";
    cout << "�������:\n";
    cout << "����, ���� ���� ����� ������\n";
    cout << "�����, ���� ���� ����� ������\n";
    cout << "������, ���� � ������\n";
    l = 0;
    r = n;
    string a;
    while (l <= r) {
      for (int i = 0; i < chisla.size(); i++) {
        if (chisla[i] == (l + r + 1) / 2) {
          t = false;
          break;
        }
      }
      if (!t) {
        break;
      }
      chisla.push_back((l + r + 1) / 2);
      cout << (l + r + 1) / 2 << '\n';
      kol++;
      cin >> a;
      while (a != "����" and a != "�����" and a != "������") {
        cout << "������������ ����\n";
        cout << "���������� �����\n";
        cin >> a;
      }
      if (a == "����") {
        l = (l + r + 1) / 2;
      }
      else if (a == "�����") {
        r = (l + r + 1) / 2;
        if (r == l + 1) {
          t = false;
          break;
        }
      }
      else if (a == "������") {
        cout << "� ������ �� " << kol << " �������\n";
        kol = 0;
        while (n != 1) {
          cout << n << '\n';
          n = (n + 1) / 2;
          kol++;
        }
        cout << n << '\n';
        cout << "������������ ����� ����� = " << kol + 1;
        t = true;
        break;
      }
    }
    if (!t) {
      cout << "�� ��������!\n";
    }
  }
}
