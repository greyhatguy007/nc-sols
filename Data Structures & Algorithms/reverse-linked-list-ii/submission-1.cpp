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
    pair<ListNode*, ListNode*> reverse(ListNode* head){
        if(head==nullptr) return {nullptr,nullptr};
        ListNode *prev=nullptr, *curr=head;
        while(curr!=nullptr){
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return {prev, head};
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dummy = new ListNode();
        dummy -> next = head;   
        ListNode *lo=dummy, *hi=dummy;
        for(int i=1;i<left && lo!=nullptr;i++) lo = lo->next;
        hi = lo->next;
        for(int i=0;i<right-left && hi!=nullptr;i++) hi = hi->next;
        ListNode* rightptr = hi->next;
        hi -> next = nullptr;
        pair<ListNode*,ListNode*> newpos = reverse(lo->next);
        lo ->next = newpos.first;
        newpos.second -> next = rightptr;
        return dummy->next;
    }
};