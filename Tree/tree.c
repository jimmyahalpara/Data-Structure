#include <stdio.h>
#include <stdlib.h>


struct node {
    int value;
    struct node *left, *right;
};

typedef struct node * NODE;
NODE tree = NULL;

// -----------Stack related operations
struct stackNode {
    NODE treeNode;
    struct stackNode * nextNode;
};
typedef struct stackNode * SNODE;
SNODE stack_tree = NULL;

void clearStack(){
    while (stack_tree != NULL){
        SNODE tmp = stack_tree;
        stack_tree = stack_tree -> nextNode;
        free(tmp);
    }
    // stack_tree = NULL;
}

void push(NODE nd){
    if (nd == NULL){
        return;
    }
    SNODE new = (SNODE)malloc(sizeof(struct stackNode));
    new -> treeNode = nd;
    new -> nextNode = stack_tree;
    stack_tree = new;
    // printf("\nPushed : %d", nd -> value);
}

NODE pop(){
    // printf("HERe");
    NODE tmp = stack_tree -> treeNode;
    SNODE stmp = stack_tree;
    stack_tree = stack_tree -> nextNode;
    // printf("\nPopped %d", tmp -> value);
    free(stmp);
    return tmp;
}

int isEmpty(){
    if (stack_tree == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void printStack(){
    printf("\nSTACK TREE: ");
    SNODE tmp = stack_tree;
    while(tmp != NULL){
        printf("%d -> ", tmp -> treeNode -> value);
        tmp = tmp -> nextNode;
        
    }
}

// -----------Stack related operation over


void preOrderWithoutRecursion(NODE root){
    if (root == NULL){
        return;
    }
    clearStack();
    push(root);
    NODE current;
    while (!isEmpty()){
        current = pop();
        printf("%d ", current -> value);
        if (current -> right != NULL){
            push(current -> right);
        }
        if (current -> left != NULL){
            push(current -> left);
        }
    }
}


void inOrderWithoutRecursion(NODE root){
    clearStack();
    NODE current = root;
    int done = 0;
    while(!done){
        if (current != NULL){
            
            push(current);
            current = current -> left;
        }
        else{
            if (!isEmpty()){
                current = pop();
                printf("%d  ", current -> value);
                current = current -> right;
                
                
            }
            else{
                done = 1;
            }
        }

    }
}


void inOrder(NODE root){
    if (root != NULL){
        inOrder(root -> left);
        printf("%d ", root -> value);
        inOrder(root -> right);
    }
}

NODE insertIntoTree(NODE root, int value){
    if (root == NULL){
        NODE n = (NODE)malloc(sizeof(struct node));
        n -> left = NULL;
        n -> right = NULL;
        n -> value = value;
        return n;
    }
    else if (root -> value == value){
        printf("Cannot add : Value already present");
        return root;
    }
    else if (value < root -> value){
        root -> left = insertIntoTree(root -> left, value);
    }
    else if (value > root -> value){
        root -> right = insertIntoTree(root -> right, value);
    }
    return root;
}

void main(){
    while(1){
        printf("\n\nSelect option from following\n");
        printf("1. To insert Node in BST\n");
        printf("2. For in order traversal\n");
        printf("3. For in order traversal without recursion\n");
        printf("4. For pre order traversal without recursion");

        int n;
        printf("\nEnter your option: ");
        scanf("%d", &n);

        if (n == 1){
            printf("\nEnter value to insert: ");
            int num;
            scanf("%d", &num);
            tree = insertIntoTree(tree, num);
        }
        else if (n == 2){
            printf("\nInorder traversal : ");
            inOrder(tree);
        }

        else if (n == 3){
            printf("\nInorder traversal without recursion: ");
            inOrderWithoutRecursion(tree);
        }
        else if (n == 4){
            printf("\nPreorder traversal without recursion: ");
            preOrderWithoutRecursion(tree);
        }
        else if (n == -1){
            break;
        }
    }
}