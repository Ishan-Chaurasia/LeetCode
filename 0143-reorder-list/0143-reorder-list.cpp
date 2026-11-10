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
    ListNode* reverseList(ListNode* head) {
        if(head==nullptr || head->next==nullptr) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* b = reverseList(slow->next);
        ListNode* a = head;
        slow->next = NULL;
        ListNode dummy(0);
        ListNode* tempC = &dummy;
        ListNode* tempA = a;
        ListNode* tempB = b;
        while(tempA && tempB) {
            tempC->next = tempA;
            tempA = tempA->next;
            tempC = tempC->next;

            tempC->next = tempB;
            tempB = tempB->next;
            tempC = tempC->next;
        }
        tempC->next = tempA;
        head = dummy.next;
    }
};