#include <stdio.h>

void insertionSortRecursive(int arr[], int n) {

  if (n <= 1) {
    return;
  }

  insertionSortRecursive(arr, n - 1);
  // 1º: arr[2] = {7,9}
  // 2º: arr[3] = {7,9,5}
  // 3º: arr[4] = {5,7,9,3}

  // 1º: n = 2
  // 2º: n = 3
  // 3º: n = 4
  int last = arr[n - 1];
  // 1º: last = arr[1] == 9
  // 2º: last = arr[2] == 5
  // 3º: last = arr[3] == 3
  int j = n - 2;
  // 1º: j = 0;
  // 2º: j = 1;
  // 3º: j = 2;

  while (j >= 0 && arr[j] > last) {
    // 1º: Não entra
    // 2º: arr[2] = 9; arr[2] === 9; arr[3] = {7,5,9}
    // 2º: arr[1] = 7; arr[1] === 7; arr[3] = {5,7,9}
    // 3º: arr[3] = 9; arr[3] === 9; arr[4] = {5,7,3,9}
    // 3º: arr[2] = 7; arr[2] === 7; arr[4] = {5,3,7,9}
    // 3º: arr[1] = 7; arr[1] === 7; arr[4] = {3,5,7,9}
    arr[j + 1] = arr[j];
    j--;
    // 2º: j = 0;
    // 3º: j = 1;
    // 3º: j = 0;
  }

  arr[j + 1] = last;
}

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[4] = {7, 9, 5, 3};
  int n = sizeof(arr) / sizeof(arr[0]);

  insertionSortRecursive(arr, n);
  printArray(arr, n);

  return 0;
}