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
  cout << "Введите количество товаров\n";
  cin >> n;
  int* a = new int[n];
  for (int i = 0; i < n; i++) {
    a[i] = rand() % 100 + 1;
  }
  cout << "Исходный массив\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';
  quick_sort(a, 0, n - 1);
  int l = 0, r = n - 1;
  int sum = 0;
  cout << "Порядок пробивания:\n";
  while (l < r) {
    sum += a[r];
    cout << a[r] << ' ';
    r--;
    cout << a[l] << ' ';
    l++;
  }
  if (n % 2 != 0) {
    cout << a[r];
    sum += a[r];
  }
  cout << '\n';
  cout << "Максимальная сумма = " << sum;
}
