#import<iostream>
#import<stdlib.h>
using namespace std;

const int n = 10;

void fill(int* num, int n) {
  for(int i = 0; i < n; i++)
    *(num + i) = (std::rand() % (100 - 25 + 1));
}

void print(int* num, int n) {
  for(int i = 0; i < n; i++)
    cout << *(num + i) << endl;
}

void bubbleSort(int* num, int n) {
  int order_ok = 0, temp = 0;
  while(n > 1 && order_ok == 0) {
    order_ok = 1;
    for(int i = 0; i < n - 1; i++)
      if(*(num + i) > *(num + i + 1)) {
        temp = *(num + i);
        *(num + i) = *(num + i + 1);
        *(num + i + 1) = temp;
        order_ok = 0;
      }
  n--;
  }
}

int main() {
  int numbers[n];
  fill(numbers, n);
  bubbleSort(numbers, n);
  print(numbers, n);

  system("pause");
}
