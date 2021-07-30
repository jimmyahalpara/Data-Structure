#include <stdio.h>

void main(){
    int ar[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 3; i++){
        for (int j = i+1; j < 3; j++){
            int tmp = ar[i][j];
            ar[i][j] = ar[j][i];
            ar[j][i] = tmp;
        }
    }
    printf("\n-----------------\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%d ", ar[i][j]);
        }
        printf("\n");
    }
}
