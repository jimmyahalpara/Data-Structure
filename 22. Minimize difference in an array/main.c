#include <stdio.h>
#include <stdlib.h>

int max_value(int a , int b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

int min_value(int a, int b){
    if (a < b){
        return a;
    }
    else{
        return b;
    }
}


void printArray(int arr[], int length){
    printf("\n");
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}


int minimizeDifference(int arr[], int length, int k){
    // int * tempArr = (int *)calloc(length * 3, sizeof(int));
    // int pointer = 0;
    int max = -99999;
    int min = 99999;
    int a,b,c;
    for (int i = 0; i < length; i ++){
        a = arr[i] - k;
        b = arr[i];
        c = arr[i] + k;

        printf("%d %d %d\n", a,b,c);
        max = max_value(max, max_value(a, max_value(b, c)));
        min = min_value(min, min_value(a, max_value(b, c)));
    }
    return max - min;
}

void main(){
    int arr[5] = {3,6,12,16,20};


    printf("%d", minimizeDifference(arr, 5, 3));

}