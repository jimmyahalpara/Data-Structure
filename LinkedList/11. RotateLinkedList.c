#include <stdio.h>
#include <string.h>
#include <ctype.h>

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


struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL || head -> next == NULL || k == 0){
        return head;
    }
    
//     int count = 1, i;
//     struct ListNode * temp = head;
//     while(temp -> next != NULL){
//         temp = temp -> next;
//         count ++;
//     }
//     temp -> next = head;
//     // count ++;
//     // printf("%d %d", count, k);
    
//     k = k % count;
//     k = count - k;
//     // temp = head;
//     for(i = 0; i < k; i++){
//         temp = temp -> next;
//     }
//     head = temp -> next;
//     temp -> next = NULL;
//     return head;
    struct ListNode *cur = head;
    int len = 1;
    while(cur -> next){
        len++;
        cur = cur -> next;
    }
    cur -> next = head;
    k = k % len;
    k = len - k;
    while(k--){
        cur = cur -> next;
    }
    head = cur -> next;
    cur -> next = NULL;
    
    return head;
    
}