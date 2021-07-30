/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
};


typedef struct ListNode LsNode;
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL || k == 1){
        return head;
    }
    LsNode * dummy = (LsNode *)malloc(sizeof(struct ListNode));
    dummy -> next = head;
    LsNode *curr = dummy, *nxt = dummy, *pre = dummy;
    
    LsNode * tmp = head;
    int count = 0;
    while(tmp != NULL){
        count ++;
        tmp = tmp -> next;
    }
    
    
    while(count >= k){
        curr = pre -> next;
        nxt = curr -> next;
        for (int i = 1; i < k; i++){
            curr -> next = nxt -> next;
            nxt -> next = pre -> next;
            pre -> next = nxt;
            nxt = curr -> next;
        }
        pre = curr;
        count -= k;
    }
    return dummy -> next;
}