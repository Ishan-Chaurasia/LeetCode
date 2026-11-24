/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;

        unordered_map<Node*, Node*> mp;
        Node* curr = head;
        Node* prev = NULL;
        Node* NewHead = NULL;
    
        while(curr) {
            Node* temp = new Node(curr->val);
            mp[curr] = temp;

            if(NewHead == NULL) {
                NewHead = temp;
                prev = NewHead;
            }
            else {
                prev->next = temp;
                prev       = temp;
            }
            curr = curr->next;
        }
        // connect the random pointers now
        curr          = head;
        Node* newCurr = NewHead;

        while(curr) {
            if(curr->random == NULL){
                newCurr->random = NULL;
            }
            else {
                newCurr->random = mp[curr->random];
            }
            curr = curr->next;
            newCurr = newCurr->next;
        }

        return NewHead;
    }
};