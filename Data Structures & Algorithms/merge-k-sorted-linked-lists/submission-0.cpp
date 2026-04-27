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
    ListNode* merge(ListNode *a,ListNode *b){
        if(!a) return b;
        if(!b) return a;
        ListNode *dummy = new ListNode();
        ListNode *ans = dummy;
        while(a && b) {
            if(a->val>b->val) {
                dummy -> next = b;
                b = b->next;
            } else {
                dummy -> next = a;
                a = a->next;
            }
            dummy = dummy -> next;
        }
        while(a){
            dummy -> next = a;
            a = a->next;
            dummy = dummy -> next;
        }
        while(b) {
            dummy -> next = b;
            b = b->next;
            dummy = dummy->next;
        }
        return ans->next;
    } 
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        while(lists.size()!=1) {
            ListNode* a = lists.back();
            lists.pop_back();
            ListNode* b = lists.back();
            lists.pop_back();
            lists.push_back(merge(a,b));
        }
        return lists.back();
    }
};
