#include<iostream>
#include<stdlib.h>
using namespace std;

const int n = 5;

void fill(int* num, int n) {
  for(int i = 0; i < n; i++)
    *(num + i) = (std::rand() % (100 - 25 + 1));
}

int findPosMax(int* num, int n) {
  int maxPos = 0;
  for(int i = 0; i < n; i++)
    if(*(num + maxPos) < *(num + i))
      maxPos = i;
  return maxPos;
}
void naiveSort(int* num, int n) {
  int p, temp;
  while(n > 1) {
    p = findPosMax(num, n);
    if(p < n - 1) {
      temp = *(num + p);
      *(num + p) = *(num + n - 1);
      *(num + n - 1) = temp;
    }
    n--;
  }
}

void print(int* num, int n) {
  for(int i = 0; i < n; i++)
    cout << *(num + i) << endl;
}
int main() {
  int numbers[n];
  fill(numbers, n);
  naiveSort(numbers, n);
  print(numbers, n);

  system("pause");

}
