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
    bool hasCycle(ListNode* head) {
        if(head==nullptr) return false;
        ListNode *s=head->next;
        if(s==nullptr) return false;
        ListNode *f = s->next;
        while(s->next != nullptr && f->next != nullptr && f->next->next !=nullptr) {
            if(f==s) return true;
            f = f->next->next;
            s = s->next;
        }
        return false;
    }
};
