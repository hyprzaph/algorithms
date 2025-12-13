#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printAll(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    bool swapped = false;    
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
	swapped = true;        
      }
    }
    if (swapped == false) {
      break;      
    }      
  }
}

int main() {

  int arr[] = {50, 32, 4, 84, 10, 48, 19, 27, 28, 70, 67, 30, 65, 16, 56, 35};
  int size = sizeof(arr) / sizeof(arr[0]);

  printAll(arr, size);
  bubbleSort(arr, size);
  printAll(arr, size);
  
  return EXIT_SUCCESS;  
}  
