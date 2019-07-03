// code for array rotation
//function rotate(int ar[], int d, int n), it rotates array of size n by d
//Time Complexity O(n * d)
//Auxiliary Space O(1)

#include <stdio.h>
void rotateLeft(int arr[], int n){
    int temp = arr[0];
    int i;
    for (i = 0; i < n-1; i++){
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void rotate(int arr[], int d, int n){
    for (int i = 0; i < d; i++){
        rotateLeft(arr, n);
    }
}

void printArray(int arr[],int  n){
    for (int i = 0; i < n ; i++){
        printf("%d, ", arr[i]);
    }
}

int main(){
    int n, d;
    printf("Enter array size:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter d:");
    scanf("%d", &d);
    rotate(arr, d,n);
    printf("Array After rotation\n");
    printArray(arr, n);
}

