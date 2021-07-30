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

struct ListNode* middleNode(struct ListNode* head){
    struct ListNode * pt1 = head;
    struct ListNode * pt2 = head;
    
    while(pt1 != NULL && pt1 -> next != NULL){
        pt1 = pt1 -> next -> next;
        pt2 = pt2 -> next;
    }
    return pt2;
}