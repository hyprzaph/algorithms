#include <stdio.h>
#include <stdlib.h>

void showAll(int *arr, int size);
void insertionSort(int *arr, int size);

int main(){

    int arr[] = {20, 81, 8, 33, 16};
    int size = sizeof(arr) / sizeof(arr[0]);

    showAll(arr, size);
    insertionSort(arr, size);
    showAll(arr, size);
    
    return EXIT_SUCCESS;
}

void showAll(int *arr, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", *(arr + i));  
    }
    printf("\n");
}

void insertionSort(int *arr, int size){
    for(int i = 0; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }   
}
