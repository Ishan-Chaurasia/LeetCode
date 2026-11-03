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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        while(temp1!=NULL && temp2!=NULL) {
            if(temp1->val <= temp2->val) {
                ListNode* t = new ListNode(temp1->val);
                tempC->next = t;
                tempC = t;
                temp1 = temp1->next;
            }
            else {
                ListNode* t = new ListNode(temp2->val);
                tempC->next = t;
                tempC = t;
                temp2 = temp2->next;
            }
        }
        if(temp1==nullptr) {
            tempC->next = temp2;
        }
        else {
            tempC->next = temp1;
        }
        return c->next;
    }
};