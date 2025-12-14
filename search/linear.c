#include <stdio.h>
#include <stdlib.h>

void printAll(int *arr, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int linearSearch(int *arr, int size, int target) {
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      return 1;      
    }      
  }    
  return 0; //neu ko tim thay  
}  

int main() {

  int arr[] = {10, 50, 30, 70, 80, 20, 90, 40};
  int size = sizeof(arr) / sizeof(arr[0]);

  printAll(arr, size);
  if (linearSearch(arr, size, 100)) {
    printf("tim thay\n");
  } else {
    printf("ko tim thay\n");
  }
  
  return EXIT_SUCCESS;  
}  
