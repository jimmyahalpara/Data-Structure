#include <stdio.h>


int stack[10];
int top;
int max;

void init(){
    top = -1;
    max = 10;
}

void push(int element){
    if (top == max - 1){
        printf("\nError Unable to push Stack Full");
    }
    else{
    top+=1;
    stack[top] = element;
    }
}

int pop(){
    if (top == -1){
        printf("\nError Unable to pop Stack Empty");
    }
    else{
    int item = stack[top];
    top-=1;
    return item;
    }
}

int peep(){
    if (top == -1){
        printf("\nError Unable to peep Stack Empty");
    }
    else{
    return stack[top];
    }
}

void printStack(){
    if (top == -1){
        printf("\nError Unable to print Stack Empty");
    }
    else{
    printf("\n");
    for (int i = top; i >=0; i--){
        printf("%d\n", stack[i]);
    }
    }
}

void change(int ind, int ele){
    if (ind > top){
        printf("Error: Unable to change: Index out of range");
    }
    stack[ind] = ele;
}

void main(){
    init();
    while(1){
    printf("\n------------------------\nEnter your options\n1. Enter 1 to Push element\n2. Enter 2 to Pop element\n3. Enter 3 to Peep element\n4. Enter 4 to Display whole stack\n5. Enter 5 to Change element\n------------------------\n");
    int n;
    printf("\nEnter you option:");
    scanf("%d", &n);
    switch(n){
    case 1:
        printf("\nEnter element to Push:");
        int ele;
        scanf("%d", &ele);
        push(ele);
        break;
    case 2:
        printf("\nPopping Element");
        int item = pop();
        printf("\nPopped element %d", item);
        break;
    case 3:
        printf("\nPeeping element %d", peep());
        break;
    case 4:
        printf("\nPrinting the stack");
        printStack();
        break;
    case 5:
        printf("\nEnter index to change:");
        int id,el;
        scanf("%d", &id);
        printf("Enter new:");
        scanf("%d", &el);
        change(id, el);
}}}
