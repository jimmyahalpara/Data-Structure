#include <stdio.h>

int max(int a, int b){
    return (a > b)? a : b;
}

void main(){
    int arr[10] = {2, 4, 1, 5, 1, 4, 5, 5, 1, 1};
    int length = 10;

    int previous = 0, current = 0, jumps = 0;

    for (int i = 0; i < length; i++){
        if (i > previous){
            jumps ++;
            previous = current;
        }
        current = max(current , i + arr[i]);
    }


    printf("Jups : %d", jumps);
}