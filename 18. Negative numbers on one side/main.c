#include <stdio.h>

void arrayProcess(int arr[], int length){
    int j = 0;
    int temp;
    for (int i = 0; i < length; i++){
        if (arr[i] < 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
        
    }
}


void printArray(int arr[], int length){
    printf("\n");
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}

void main(){
    int arry[7] = {-1, -2, 5, 6, 7, -2, -4};
    int length = 7;

    arrayProcess(arry, length);
    printArray(arry, length);

}