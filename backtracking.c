#include <stdio.h>
#include <stdlib.h>

int n = 5, k = 2, m = 3;
int arr[100];
int numOfZero = 0;
int numOfOne = 0;

void backtrack(int i){
  if(i == n){
    if(numOfOne == k){
      for(int j = 0; j < n; j++){
	printf("%d ", arr[j]);
      }
      printf("\n");
    }
    return;
  }

  if(numOfOne < k){
    arr[i] = 1;
    int oldZero = numOfZero;
    numOfZero = 0;
    numOfOne++;
    backtrack(i + 1);

    //hoan tac
    numOfOne = oldZero;
    numOfOne--;
  }

  if(numOfZero + 1 < m){
    arr[i] = 0;
    numOfZero++;
    backtrack(i + 1);
    numOfZero--;
  }
}

int main(){

  backtrack(0);
  
  return EXIT_SUCCESS;
}
