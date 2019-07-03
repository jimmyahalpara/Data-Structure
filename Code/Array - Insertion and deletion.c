//made by Jimmy Kumar Ahalpara
//insertion complexity O(n)
//Deletion complexity O(n)

#include <stdio.h>

int insertion(int ar[], int size, int element, int place, int filled){
    if (filled == size){
        printf("\nError: Unable to insert: Array Full");
        return filled;
    }
    for (int i = size - 2; i >= place; i--){
        ar[i+1] = ar[i];
    }
    ar[place] = element;
    return filled+1;
}

int deleteArray(int arr[], int place, int filled, int size){
    if (filled == -1){
        printf("Error: Unable to delete: Array empty");
        return filled;
    }
    for (int i = place; i < size-1; i++){
        arr[i] = arr[i+1];
    }
    return filled-1;
}

void printArray(int ar[], int filled){
    printf("\n");
    for (int i = 0; i <= filled; i++){
            printf("%d, ", ar[i]);
    }
}

void main(){
    int n;
    printf("Enter size of array:");
    scanf("%d", &n);
    int arr[n];
    int filled = -1;
    printf("Enter array elements..\n");
    int element,i = 0;
    while(i < n && element != -1){
        scanf("%d", &element);
        arr[i] = element;
        if (element != -1){
            i++;
            filled++;
        }
    }
    printf("Your array is --");
    printArray(arr, filled);
    int option = 0;
    while (option != -1){
        printf("\nEnter your options\n1. Enter 1 to insert \n2. Enter 2 to delete\n3. Enter 3 to print array");
        printf("\nEnter you option:");
        scanf("%d", &option);
        if (option == 1){
            int ele;
            printf("Enter the element to enter:");
            scanf("%d", &ele);
            int pos;
            printf("Enter the index you want place the position:");
            scanf("%d", &pos);
            filled = insertion(arr, n, ele, pos, filled);
        }
        else if(option == 2){
            printf("Enter the index you want to delete element:");
            int index;
            scanf("%d", &index);
            filled = deleteArray(arr, index, filled, n);
        }
        else if(option == 3){
            printArray(arr, filled);
        }
    }
}
