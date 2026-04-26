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
    ListNode* revers(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode *odd = head, *even = head;
        while (even->next != nullptr && even->next->next != nullptr) {
            odd = odd->next;
            even = even->next->next;
        }
        ListNode* evenhead = odd->next;
        odd->next = nullptr;


        evenhead = revers(evenhead);


        ListNode* first = head;
        ListNode* second = evenhead;
        while (first != nullptr && second != nullptr) {
            ListNode* oddtemp = first->next;
            ListNode* eventemp = second->next;
            first->next = second;
            second->next = oddtemp;
            first = oddtemp;
            second = eventemp;
        }
    }
};
