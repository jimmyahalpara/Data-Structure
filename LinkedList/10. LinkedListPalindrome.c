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

int isPalindrome(struct ListNode* head){
    if (head == NULL || head -> next == NULL){
        return 1;
    }
    
    struct ListNode * slow = head, *fast = head;
    while(fast -> next && fast -> next -> next){
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    
    slow -> next = reverseList(slow -> next);
    slow = slow -> next;
    while(slow != NULL){
        if (head -> val != slow -> val){
            return 0;
        }
        head = head -> next;
        slow = slow -> next;
    }
    return 1;
}