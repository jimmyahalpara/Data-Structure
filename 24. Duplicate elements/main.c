#include <stdio.h>


void main(){
    int arr[10] = {1,2,9,3,9,6,4,8,7,5};
    int length = 10;

    int hare = arr[0];
    int tortoise = arr[0];

    do
    {
        
        hare = arr[arr[hare]];
        tortoise = arr[tortoise];
        printf(" 1st Phase hare %d tor %d\n", hare, tortoise);

    } while (hare != tortoise);

    tortoise = arr[0];
    while (tortoise != hare){
        tortoise = arr[tortoise];
        hare = arr[hare];
        printf(" 2nd phase hare %d tor %d\n", hare, tortoise);
    }

    printf("Duplicate element is :%d", hare);
    

}