#include <stdio.h>

int max(int a, int b){
    if (a > b) return a;
    else return b;
}

void main(){
    int arr[8] = {2, 3, 4, -1, -2, 1, 5, -3};

    
    int length = 8;
    int max_so_far = -999, max_ending_here = 0;
    int start = 0;
    int end = 0;
    int s = 0;
    for (int i = 0; i < length; i++){
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here){
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }
        if (max_ending_here < 0){
            max_ending_here = 0;
            s = i + 1;
        }
    }

    printf("%d", max_so_far);
    printf(" Start - %d End - %d", start, end);
}