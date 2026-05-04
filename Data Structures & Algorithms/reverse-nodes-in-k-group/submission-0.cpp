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

    pair<ListNode*,ListNode*> reverse(ListNode* head){
        ListNode *last = head;
        ListNode *curr = head;
        ListNode *prev = nullptr;
        while(curr!=nullptr){
            ListNode* temp = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = temp;
        }
        return {prev, last};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* curr = dummy;
        while(curr!=nullptr){
            int ctr = k;
            ListNode* begin = curr;
            while(ctr--){
                curr = curr->next;
                if(curr==nullptr) return dummy->next;
            }
            ListNode* attachment = curr->next;
            curr -> next = nullptr;

            pair<ListNode*,ListNode*> res = reverse(begin->next);
            begin->next = res.first;
            res.second->next = attachment;

            curr = res.second;
        }
        return dummy->next;
    }
};
