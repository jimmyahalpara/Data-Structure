#include <stdio.h>

int binary_search(int ar[], int size, int element){
    int low = 0;
    int high = size - 1;
    while(low <= high){
        int mid = (high + low)/2;
        if (element < ar[mid]){
            high = mid-1;
        }
        else if (element > ar[mid]){
            low = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

void sort(int ar[], int size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size-1; j++){
            if (ar[j]>ar[j+1]){
                int temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
    }
}

void main(){
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int ar[n];
    printf("Enter array elements...\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &ar[i]);
    }
    sort(ar, n);
    printf("sorted array is: ");
    for (int j = 0; j < n; j++){
        printf("%d, ",ar[j]);
    }
    int element;
    printf("\nEnter element you want to search for:");
    scanf("%d", &element);
    int pos = binary_search(ar, n, element);
    if (pos == -1){
        printf("\nYour element does not exist..");
    }
    else{
        printf("\nYour element exist at position %d", pos);
    }
}
