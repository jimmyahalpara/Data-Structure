#include <stdio.h>

void printArray(int arr[], int length){
    printf("\n");
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}

int NextGap(int gap){
    if (gap <= 1){
        return 0;
    }
    else{
        return (gap / 2) + (gap % 2);
    }
}

void swap(int * a, int * b){
    int temp = * a;
    * a = * b;
    * b = temp;
}

void Merge(int arr1[], int arr2[], int a, int b){
    int gap = a + b;
    gap = NextGap(gap);

    while(gap > 0){
        // printf("%d " ,gap);
        int i = 0;
        while ((i+gap) < a){
            if (arr1[i] > arr1[i + gap]){
                swap(&arr1[i] , &arr2[i+gap]);
                
            }
            i++;
            // printf("a");
        }
        int j = (gap > a) ? gap - a : 0;
        while (i < a && j < b){
            if (arr1[i] > arr2[j]){
                swap(&arr1[i], &arr2[j]);
            }
            j++;
            i++;
            // printf("b");
        }

        if (j < b){
            j = 0;
            while ((j + gap) < b){
                if (arr2[j] > arr2[j+gap]){
                    swap(&arr2[j] , &arr2[j+gap]);
                }
                j++;
                // printf("c");
            }
        }

        gap = NextGap(gap);

    }
}

void main(){
    int arr1[8] = {2,3,7,8,9,30,50,60};
    int arr2[10] = {10, 12,13,14,15,16,17,18,20,22};
    int l1 = 8;
    int l2 = 10;

    Merge(arr1, arr2, l1, l2);
    printf("\nFirst array :");
    printArray(arr1, 5);
    printf("\nSecond array :");
    printArray(arr2, 10);

}