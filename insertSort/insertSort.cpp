#include<iostream>
using namespace std;

const int n = 50;

void fill(int* num, int n) {
  for(int i = 0; i < n; i++)
    *(num + i) = (std::rand() % (100 - 25 + 1));
}

void insMin(int* num, int pos) {
  int i = pos - 1, x = *(num + pos);
  while(i >= 0 && x < *(num + i)) {
    *(num + i + 1) = *(num + i);
    i--;
  }
  *(num + i + 1) = x;
}

void insertSort(int* num, int n) {
  int i;
  for(int k < 1; k < n; k++)
    insMin(num, k);
}

void print(int* num, int n) {
  for(int i = 0; i < n; i++)
    cout << *(num + i) << endl;
}

int main() {
  int numbers[n];
  fill(numbers, n);
  insertSort(numbers, n);
  print(numbers, n)

  getchar();
}
