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

void merge(int* num, int beg, int mid, int end, int* numOrd) {
  int i = beg, j = mid, k = beg;
  while(i <= mid - 1 && j <= end) {
    if(*(num + i) < *(num + j)) {
      *(numOrd + k) = *(num + i);
      i++;
    } else {
      *(numOrd + k) = *(num + j);
      j++;
    }
    k++;
  }
  while(i <= mid  - 1) {
    *(numOrd + k) = *(num + i);
    i++; k++;
  }
  while(j <= end) {
    *(numOrd + k) = *(num + j);
    j++; k++;
  }
  for(i = beg; i <= end; i++)
    *(num + i) = *(numOrd + i);
}

void mergeSort(int* num, int begin, int end, int* numOrd) {
  int middle;
  if(begin < end) {
    middle = (begin + end) / 2;
    mergeSort(num, begin, middle, numOrd);
    mergeSort(num, middle + 1, end, numOrd);
    merge(num, begin, middle + 1, end, numOrd);
  }
}

int main() {
  int numbers[n], numbersOrd[n], begin = 0, end = 50;
  fill(numbers, n);
  mergeSort(numbers, begin, end, numbersOrd);
  print(numbers, n);

  getchar();
}
