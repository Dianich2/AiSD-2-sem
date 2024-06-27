#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <random>
#include <ctime>
using namespace std;

void quick_sort(int*& a, int first, int last) { // быстрая сортировка
  int middle;
  int l = first, r = last;
  middle = a[(l + r) / 2];
  while (l < r) {
    while (a[l] < middle) l++;
    while (a[r] > middle) r--;
    if (l <= r) {
      swap(a[l], a[r]);
      l++;
      r--;
    }
  }
  if (first < r)  quick_sort(a, first, r);
  if (l < last) quick_sort(a, l, last);
}

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  srand(time(NULL));
  int n;
  cout << "Введите количество участников\n";
  cin >> n;
  vector<int> g;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 10 + 1;
  }
  cout << "Исходный массив\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  quick_sort(a, 0, n - 1);
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  int kol = 0;
  int dif = 1000;
  n--;
  int kol_dif = 0;
  while (kol_dif <= 3 && n > -1) {
    if (a[n] == dif) {
      kol++;
    }
    else {
      g.push_back(a[n]);
      dif = a[n];
      kol_dif++;
      kol++;
    }
    n--;
  }
  if (n == -1 && kol_dif!= 4) {
    cout << "Количество призеров = " << kol << '\n';
  }
  else {
    cout << "Количество призеров = " << kol - 1 << '\n';
  }
  if (g.size() < 3) {
    for (int i = 0; i < g.size(); i++) {
      cout << g[i] << ' ';
    }
  }
  else {
    for (int i = 0; i < 3; i++) {
      cout << g[i] << ' ';
    }
  }
}
