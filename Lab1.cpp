#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <ctime>
using namespace std;

unsigned long long int fib(long long int n) {
  if (n == 0) {
    return 0;
  }
  if (n == 1 or n == 2) {
    return 1;
  }
  else {
    return fib(n - 1) + fib(n - 2);
  }
}

void saytime(double& duration) {
  int min = (int)duration / 60;
  int sec = (int)duration - (min * 60);
  cout << "–асчетное врем€" << ' ';
  if (min < 10) {
    cout << 0 << min << " минут" << ' ';
  }
  else {
    cout << min << " минут" << ' ';
  }
  if (sec < 10) {
    cout << 0 << sec << " секунд\n";
  }
  else {
    cout << sec << " секунд\n";
  }
}

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  unsigned long long int n;
  cin >> n;
  unsigned long long int a = 1, b = 1, c = 0;
  clock_t start = clock();
  if (n == 0) {
    cout << 0 << '\n';
  }
  else if (n == 1 or n == 2) {
    cout << a << '\n';
  }
  else {
    for (int i = 2; i < n; i++) {
      c = a + b;
      a = b;
      b = c;
    }
    cout << c << '\n';
  }
  clock_t end = clock();
  double duration = (float)(end - start) / CLOCKS_PER_SEC;
  printf("%.5f \n", duration);
  saytime(duration);

  start = clock();
  c = fib(n);
  cout << c << '\n';
  end = clock();
  duration = (float)(end - start) / CLOCKS_PER_SEC;
  printf("%.5f \n", duration);
  saytime(duration);
}
