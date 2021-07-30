#include <stdio.h>

int linear_search(int ar[], int size, int element){
    int position = -1;
    for (int i = 0 ; i < size; i++){
        if (ar[i] == element){
            position = i;
        }
    }
    return position;
}

void main(){
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int ar[n];
    printf("Enter array elements...");
    for (int i = 0; i < n; i++){
        scanf("%d", &ar[i]);
    }
    printf("\nYour array is:");
    for (int j = 0; j < n; j++){
        printf("%d, ", ar[j]);
    }
    printf("\nEnter element you want to search:");
    int element;
    scanf("%d", &element);
    int pos = linear_search(ar, n, element);
    if (pos == -1){
        printf("\nYour element not found!!");
    }
    else{
        printf("\nYour element found at %d", pos);
    }
}
