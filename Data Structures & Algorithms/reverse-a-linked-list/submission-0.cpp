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
        ListNode *tmp, *n;
        if(head == nullptr || head->next==nullptr) return head;
        tmp = head->next;
        head->next = nullptr;
        while(tmp!=nullptr){
            n = tmp->next;
            tmp -> next = head;
            head = tmp;
            tmp = n;
        }
        return head;
    }
};
