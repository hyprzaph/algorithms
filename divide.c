#include <stdio.h>
#include <stdlib.h>

int divide(int *a, int left, int right){
  if(left == right) return a[left];
  int mid = (left + right) / 2;

  int maxLeft = divide(a, left, mid);
  int maxRight = divide(a, mid + 1, right);

  return (maxLeft > maxRight) ? maxLeft : maxRight;
  
}

int main(){
  
  int a[] = {3, 9, 2, 7, 11, 5};
  int size = sizeof(a) / sizeof(a[0]);

  printf("%d ", divide(a, 0, size - 1));
  
  return EXIT_SUCCESS;
}
