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
  cout << "Давайте сыграем в игру. Вы загадаете число, а я буду угадывать.\n";
  cout << "Введите диапозон для угадывания\n";
  cin >> n;
  if (n == 0) {
    cout << "Некорректный ввод\n";
  }
  else {
    cout << "Теперь вы мне будете давать подсказки\n";
    cout << "Введите:\n";
    cout << "мало, если ваше число больше\n";
    cout << "много, если ваше число меньше\n";
    cout << "угадал, если я угадал\n";
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
      while (a != "мало" and a != "много" and a != "угадал") {
        cout << "Некорректный ввод\n";
        cout << "Попробуйте снова\n";
        cin >> a;
      }
      if (a == "мало") {
        l = (l + r + 1) / 2;
      }
      else if (a == "много") {
        r = (l + r + 1) / 2;
        if (r == l + 1) {
          t = false;
          break;
        }
      }
      else if (a == "угадал") {
        cout << "Я угадал за " << kol << " попыток\n";
        kol = 0;
        while (n != 1) {
          cout << n << '\n';
          n = (n + 1) / 2;
          kol++;
        }
        cout << n << '\n';
        cout << "Максимальное число шагов = " << kol + 1;
        t = true;
        break;
      }
    }
    if (!t) {
      cout << "Вы обманщик!\n";
    }
  }
}
