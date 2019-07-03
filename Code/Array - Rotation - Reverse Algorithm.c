// code for array rotation
//function rotate(int ar[], int d, int n), it rotates array of size n by d
//Time Complexity O(n)

#include <stdio.h>
void reverse(int arr[], int start, int end){
    while (start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end --;
    }
}

void rotate(int arr[], int d, int n){
    reverse(arr, 0 , d - 1);
    reverse(arr, d , n - 1);
    reverse(arr, 0 , n - 1);
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

