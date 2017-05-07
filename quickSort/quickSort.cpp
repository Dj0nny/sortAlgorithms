#include<iostream>
using namespace std;

const int n = 50;

void fill(int* num, int n) {
  for(int i = 0; i < n; i++)
    *(num + i) = (std::rand() % (100 - 25 + 1));
}

void print(int* num, int n) {
  for(int i = 0; i < n; i++)
    cout << *(num + i) << endl;
}

void quickSort(int* num, int begin, int end) {
  int i = begin, j = end;, temp, pivot = *(num + ((begin + end) / 2));
  while(i <= j) {
    while(*(num + i) < pivot)
      i++;
    while(*(num + j) > pivot)
      j--;
    if(i <= j) {
      temp = *(num + i);
      *(num + i) = *(num +j);
      *(num + j) = temp;
      j--;
      i++;
    }
  }

  if(begin < j)
    quickSort(num, begin, j);
  if(begin < end)
    quickSort(num, i, end);

}

int main() {
  int numbers[n], begin = 0, end = n;

  fill(numbers, n);
  quickSort(numbers, begin, end);
  print(numbers, n);

  getchar();
}
