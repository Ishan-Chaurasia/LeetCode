/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        while(a!=nullptr && b!=nullptr){
            if(a->val <= b->val) {
            tempC->next = a;
            a = a->next;
            tempC = tempC->next;
            }
            else {
                tempC->next = b;
                b = b->next;
                tempC = tempC->next;
            }
        }
        if(a == nullptr) tempC->next = b;
        else tempC->next = a;
        return c->next;
    }
};