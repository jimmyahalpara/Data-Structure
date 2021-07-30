#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
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

int hasCycle(struct ListNode *head) {
    if (head == NULL){
        return NULL;
    }
    struct ListNode * fast = head;
    struct ListNode * slow = head;
    
    while(fast && slow && fast -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
        if (fast == slow){
            return 1;
        }
    }
    return 0;
}