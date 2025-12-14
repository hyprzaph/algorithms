#include <stdio.h>
#include <stdlib.h>

void printAll(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

int binarySearch(int *arr, int left, int right, int key, int mid) {
  mid = left + (right - left) / 2;
  if (left <= right) {
    if (arr[mid] == key) {
      return 1;
    }
    if (arr[mid] < key) {
      return binarySearch(arr, mid + 1, right, key, mid);
    }
    if (arr[mid] > key) {
      return binarySearch(arr, left, mid - 1, key, mid);       
    }    
  }
  return 0;  
}

void binary(int *arr, int size) {
  int left = 0, right = size - 1;
  int key = 1;
  if (binarySearch(arr, left, right, key, 0)) {
    printf("ok tim thay roi nha\n");
  } else {
    printf("ko tim thay roi nha\n");    
  }
}

int main() {
  
  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int size = sizeof(arr) / sizeof(arr[0]);

  printAll(arr, size);
  binary(arr, size);  
  
  return EXIT_SUCCESS;  
}  
