/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* t = head;
        while(t != NULL) {
            Node* a = t->next;
            if(t->child != NULL) {
                Node* c = t->child;
                t->child = NULL;
                c = flatten(c); // Recursion
                t->next = c;
                c->prev = t;
                while(c->next!=NULL) {
                    c = c->next;
                }
                c->next = a;
                if(a!=NULL)a->prev = c;
            }
            t = a;
        }
        return head;
    }
};