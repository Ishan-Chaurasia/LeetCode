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
    ListNode* partition(ListNode* head, int x) {
        ListNode small(0);
        ListNode large(0);

        ListNode* a = &small;
        ListNode* b = &large;

        while(head!=nullptr) {
            if(head->val < x) {
                a->next = head;
                a = a->next;
            }
            else {
                b->next = head;
                b = b->next;
            }
            head = head->next;
        }
        b->next = nullptr;
        a->next = large.next;
        return small.next;
    }
};