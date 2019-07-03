// code for array rotation
//function rotate(int arr[], int d, int n), it rotates array of size n by d
//Time Complexity O(n)
//Auxiliary Space O(1)

#include <stdio.h>

int g_c_d(int a, int b){
    if (b == 0){
        return a;
    }
    else{
        return g_c_d(b, a % b);
    }
}

void rotate(int arr[], int d, int n)
{
    int i, j, k, temp;
    int gcd = g_c_d(d, n);
    printf("%d", gcd);
    for (i = 0; i < gcd; i++) {
        /* move i-th values of blocks */
        temp = arr[i];
        j = i;
        while (1) {
            k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
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

