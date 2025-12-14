#include <stdio.h>
#include <stdlib.h>

void printAll(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", *(arr + i));
  }
  printf("\n");
}

int binarySearch(int *arr, int size, int target) {
  int left = 0, right = size - 1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
      return 1; // yesssss sirr
    } else if (arr[mid] < target) {
      left = mid + 1;
    } else if (arr[mid] > target) {
      right = mid - 1;      
    }      
  }    
  return 0; //neu ko tim thay  
}  
int main() {

  int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
  int size = sizeof(arr) / sizeof(arr[0]);

  printAll(arr, size);

  if (binarySearch(arr, size, 69420)) {
    printf("tim thay nha!\n");
  } else {
    printf("ko tim thay nha!\n");
  }
  
  return EXIT_SUCCESS;  
}  
