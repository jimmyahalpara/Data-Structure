// add two numbers given as linked list.
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

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * dummy = (struct ListNode *)malloc(sizeof(struct ListNode));
    dummy -> next = NULL;
    dummy -> val = 0;
    struct ListNode * tmp = dummy;
    int sum;
    int carry = 0;
    while(l1 != NULL || l2 != NULL || carry){
        int sum = 0;
        if (l1 != NULL){
            sum += l1 -> val;
            l1 = l1 -> next;
        }
        if (l2 != NULL){
            sum += l2 -> val;
            l2 = l2 -> next;
        }
        
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        struct ListNode * new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new -> next = NULL;
        new -> val = sum;
        tmp -> next = new ;
        tmp = new;
        
    }
    return dummy -> next;
    
}