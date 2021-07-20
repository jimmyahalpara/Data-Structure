#include <stdio.h>
int intersection_function(int arr1[],int arr2[], int final_array[], int len1, int len2){
    int i = 0;
    int l1 = 0;
    int l2 = 0;
    while (l1 < len1 && l2 < len2){
        if (arr1[l1] < arr2[l2]){
            l1++;
        }
        else if (arr1[l1] > arr2[l2]){
            l2++;
        }
        else{
            final_array[i] = arr1[l1];
            i++;
            l1++;
            l2++;
        }
    }
    return i;
}





int union_function(int arr1[],int arr2[], int final_array[], int len1, int len2){
    int i = 0;
    int l1 = 0;
    int l2 = 0;
    while (l1 < len1 && l2 < len2){
        if (arr1[l1] < arr2[l2]){
            final_array[i] = arr1[l1];
            i++;
            l1++;
        }
        else if (arr1[l1] > arr2[l2]){
            final_array[i] = arr2[l2];
            i++;
            l2++;
        }
        else{
            final_array[i] = arr1[l1];
            i++;
            l1++;
            l2++;
        }
    }

    while (l1 < len1){
        final_array[i] = arr1[l1];
        i++;
        l1++;
    }
    while (l2 < len2){
        final_array[i] = arr2[l2];
        i++;
        l2++;
    }

    return i;
}


void printArray(int arr[], int length){
    printf("\n");
    for (int i = 0; i < length; i++){
        printf("%d ", arr[i]);
    }
}


void main(){
    int array1[10] = {0,3,4,6,9,10,12,15,16,18};
    int array2[10] = {1,3,5,7,9,11,13,15,17,19};

    int union_array[30] = {0};
    int intersection_array[30] = {0};

    printf("Union - ");
    int union_length = union_function(array1, array2, union_array, 10, 10);
    printArray(union_array, union_length);

    printf("\nIntersection - ");
    int intersection_length = intersection_function(array1, array2, intersection_array, 10, 10);
    printArray(intersection_array, intersection_length);



}