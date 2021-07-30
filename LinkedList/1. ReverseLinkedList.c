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

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL){
        return NULL;
    }
    struct ListNode* d = NULL;
    struct ListNode* hd = head;
    struct ListNode* next;
    while(hd != NULL){
        next = hd -> next;
        hd -> next = d;
        d = hd;
        hd = next;
        
    }
    return d;
}