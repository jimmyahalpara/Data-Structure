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

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (l1 == NULL) return l2;
    else if (l2 == NULL) return l1;
    struct ListNode * tmp;
    struct ListNode * res;
    if (l1 -> val > l2 -> val){
        tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    res = l1;
    while(l1 != NULL && l2 != NULL){
        tmp = NULL;
        while(l1 != NULL && l1 -> val <= l2 -> val){
            tmp = l1;
            l1 = l1 -> next;
        }
        tmp -> next = l2;
        
        
        tmp = l1;
        l1 = l2;
        l2 = tmp;
    }
    return res;
    
}