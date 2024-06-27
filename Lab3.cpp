#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <random>
#include <ctime>
using namespace std;

void bubble_sort(int*& b, int n) { // пузырьковая сортировка
  while (n--) {
    bool t = false;
    for (int i = 0; i < n; i++) {
      if (b[i] > b[i + 1]) {
        swap(b[i], b[i + 1]);
        t = true;
      }
    }
    if (!t) {
      break;
    }
  }
}

void insert_sort(int*& c, int n) { // сортировка вставками
  for (int i = 1; i < n; i++) {
    int sort = i - 1;
    while (sort > -1 and c[sort] > c[sort + 1]) {
      swap(c[sort], c[sort + 1]);
      sort--;
    }
  }
}

void choice_sort(int*& d, int n) { // сортировка выбором
  for (int i = 0; i < n - 1; i++) {
    int min_poz = i;
    for (int j = i + 1; j < n; j++) {
      if (d[j] < d[min_poz]) {
        min_poz = j;
      }
    }
    if (min_poz != i) {
      swap(d[i], d[min_poz]);
    }
  }
}

void quick_sort(int*& e, int first, int last) { // быстрая сортировка
  int middle;
  int l = first, r = last;
  middle = e[(l + r) / 2];
  while (l < r) {
    while (e[l] < middle) l++;
    while (e[r] > middle) r--;
    if (l <= r) {
      swap(e[l], e[r]);
      l++;
      r--;
    }
  }
  if (first < r) quick_sort(e, first, r);
  if (l < last) quick_sort(e, l, last);
}

void mysort(int*& a, int n) { // моя сортировка
  int i = 0;
  while (i <= n - i - 1) {
    int min = i;
    int max = n - i - 1;
    for (int j = i; j < n - i; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
      if (a[j] > a[max]) {
        max = j;
      }
    }
    if (i == max and n - i - 1 == min) {
      swap(a[i], a[n - i - 1]);
    }
    else if (i == max) {
      int temp = a[n - i - 1];
      a[n - i - 1] = a[max];
      a[i] = a[min];
      a[min] = temp;
    }
    else if (n - i - 1 == min) {
      int temp = a[i];
      a[i] = a[min];
      a[n - i - 1] = a[max];
      a[max] = temp;
    }
    else {
      swap(a[i], a[min]);
      swap(a[n - i - 1], a[max]);
    }
    i++;
  }
}

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  srand(time(NULL));
  int n;
  cin >> n;
  int* a = new int[n];
  int* b = new int[n];
  int* c = new int[n];
  int* d = new int[n];
  int* e = new int[n];
  int* f = new int[n];
  for (int i = 0; i < n; i++) {
    a[i] = b[i] = c[i] = d[i] = e[i] = f[i] = rand() % 100000 + 1;
  }
  cout << "Исходный массив:\n";
  for (int i = 0; i < n; i++) {
    cout << a[i] << ' ';
  }
  cout << '\n';

  clock_t start = clock();
  bubble_sort(b, n);
  clock_t end = clock();
  cout << "Пузырьковая сортировка:\n";
  for (int i = 0; i < n; i++) {
    cout << b[i] << ' ';
  }
  cout << '\n';
  double duration = (float)(end - start) / CLOCKS_PER_SEC;
  printf("Время работы = %.5f секунд\n", duration);

  start = clock();
  insert_sort(c, n);
  end = clock();
  cout << "Сортировка вставками:\n";
  for (int i = 0; i < n; i++) {
    cout << c[i] << ' ';
  }
  cout << '\n';
  duration = (float)(end - start) / CLOCKS_PER_SEC;
  printf("Время работы = %.5f секунд\n", duration);

  start = clock();
  choice_sort(d, n);
  end = clock();
  cout << "Сортировка выбором:\n";
  for (int i = 0; i < n; i++) {
    cout << d[i] << ' ';
  }
  cout << '\n';
  duration = (float)(end - start) / CLOCKS_PER_SEC;
  printf("Время работы = %.5f секунд\n", duration);

  start = clock();
  quick_sort(e, 0, n - 1);
  end = clock();
  cout << "Быстрая сортировка:\n";
  for (int i = 0; i < n; i++) {
    cout << e[i] << ' ';
  }
  cout << '\n';
  duration = (float)(end - start) / CLOCKS_PER_SEC;
  printf("Время работы = %.5f секунд\n", duration);

  start = clock();
  mysort(f, n);
  end = clock();
  cout << "Моя сортировка:\n";
  for (int i = 0; i < n; i++) {
    cout << f[i] << ' ';
  }
  cout << '\n';
  duration = (float)(end - start) / CLOCKS_PER_SEC;
  printf("Время работы = %.5f секунд\n", duration);
}

