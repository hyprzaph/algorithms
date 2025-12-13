#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printAll(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void selectionSort(int *arr, int size) {
  for (int i = 0; i < size - 1; i++) {
    int index = i;
    for (int j = i + 1; j < size; j++) {
      if (arr[j] < arr[index]) {
        index = j;
      }
    }
    int tmp = arr[i];
    arr[i] = arr[index];
    arr[index] = tmp;    
  }
}

int main() {

  int arr[] = {72, 21, 58, 55, 68, 46, 47};
  int size = sizeof(arr) / sizeof(arr[0]);

  printAll(arr, size);
  selectionSort(arr, size);
  printAll(arr, size);  
  
  return EXIT_SUCCESS;  
}
