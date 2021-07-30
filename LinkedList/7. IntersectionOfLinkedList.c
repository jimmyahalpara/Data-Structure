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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *d1 = headA;
    struct ListNode *d2 = headB;
    
    while(d1 != d2){
        if (d1 == NULL){
            d1 = headB;
        }
        else{
            d1 = d1 -> next;
        }
        if (d2 == NULL){
            d2 = headA;
        }
        else{
            d2 = d2 -> next;
        }
    }
    if (d1 == d2 == NULL){
        return NULL;
    }
    else{
        return d1;
    }
    
    
}