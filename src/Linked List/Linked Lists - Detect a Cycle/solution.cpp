/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    Node *cur1 = head;
    Node *cur2 = head;
    while (cur1 && cur2) {
        if(cur1 -> next) {
            cur1 = cur1->next->next;
        }
        cur2 = cur2->next;
        if (cur1 != NULL && (cur1==cur2)) {
            return true;
        }
    }
    return false;
}