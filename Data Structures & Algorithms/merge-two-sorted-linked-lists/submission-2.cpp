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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {\
        if(list1==nullptr) return list2;
        if(list2==nullptr) return list1;

        ListNode *a = list1, *b=list2;
        ListNode* ans = new ListNode;
        if(a->val<b->val){
            ans = a;
            a = a->next;
        } else {
            ans = b;
            b = b->next;
        }
        ListNode* curr = ans;
        while(a!=nullptr && b!=nullptr){
            if(a->val<=b->val){
                curr -> next = a;
                a = a->next;
            } else {
                curr -> next = b;
                b = b -> next;
            }
            curr = curr -> next;
        }
        while(a!=nullptr) {
            curr -> next = a;
            a = a-> next;
            curr = curr->next;
        }
        while(b!=nullptr){
            curr -> next = b;
            b = b -> next;
            curr = curr -> next;
        }
        return ans;
    }
};
