// it is guranteed that the node to be deleted is not a tail node.
//  if not guranteed, use simple if condition.

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
void deleteNode(struct ListNode* node) {
    node -> val = node -> next -> val;
    node -> next = node -> next -> next;
}