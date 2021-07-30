#include <stdio.h>

void rotateByOne(int arr[], int length){
    int i = 0;
    int j = length - 1;
    int temp;
    while (i != j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
    }
}


void printArray(int arr[], int length){
    printf("\n");
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arr[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    
    rotateByOne(arr, 20);
    printArray(arr, 20);


}