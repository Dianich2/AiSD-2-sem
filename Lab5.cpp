#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <stack>
#include <string>
using namespace std;

struct Mystack {
  char sym;
  Mystack* next;
};

void push(Mystack*& a, char s) {
  Mystack* temp = new Mystack;
  temp->sym = s;
  temp->next = a;
  a = temp;
}

void pop(Mystack*& a) {
  if (a == NULL) {
    exit(-1);
  }
  Mystack* temp = a;
  a = a->next;
  delete temp;
}

char top(Mystack*& a) {
  if (a == NULL) {
    exit(-1);
  }
  return a->sym;
}

int size(Mystack* a) {
  Mystack* temp = a;
  int kol = 0;
  while (temp) {
    kol++;
    temp = temp->next;
  }
  return kol;
}


bool check(char f, char g) {
  if (f == ')') {
    if (g == '(') {
      return 1;
    }
    return 0;
  }
  else if (f == ']') {
    if (g == '[') {
      return 1;
    }
    return 0;
  }
  else if (f == '}') {
    if (g == '{') {
      return 1;
    }
    return 0;
  }
}

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  string b;
  getline(cin, b);
  Mystack* c = nullptr;
  bool t = true;
  bool k = false;
  for (int i = 0; i < b.length(); i++) {
    if (b[i] == '(' or b[i] == '[' or b[i] == '{') {
      push(c, b[i]);
      k = true;
    }
    else if (b[i] == ')' or b[i] == ']' or b[i] == '}') {
      if (size(c) != 0) {
        if (!check(b[i], top(c))) {
          t = false;
          break;
        }
        else {
          pop(c);
        }
      }
      else {
        t = false;
        k = true;
        break;
      }
    }
  }
  if (size(c) != 0) {
    t = false;
  }
  if (!k) {
    cout << "В последовательности нет скобок\n";
  }
  else if (t) {
    cout << "Скобки расставлены верно\n";
  }
  else {
    cout << "Скобки расставлены не верно\n";
  }
}
