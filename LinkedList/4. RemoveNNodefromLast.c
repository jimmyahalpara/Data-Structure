#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode* dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy -> val = NULL;
    dummy -> next = head;
    
    
    struct ListNode * f = dummy;
    struct ListNode * s = dummy;
    for (int i = 1; i<= n; i++){
        f = f -> next;
    }
    
    while(f -> next != NULL){
        f = f -> next;
        s = s -> next;
    }
    
    s -> next = s -> next -> next;
    return dummy -> next;
}