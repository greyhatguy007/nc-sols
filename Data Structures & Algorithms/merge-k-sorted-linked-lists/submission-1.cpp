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
    struct comparenodes{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        priority_queue<ListNode*, vector<ListNode*>, comparenodes> minheap; 
        for(ListNode* &node : lists) minheap.push(node);
        while(!minheap.empty()){
            ListNode* temp = minheap.top();
            curr -> next = temp;
            curr = curr->next;
            minheap.pop();
            temp = temp->next;
            if(temp!=nullptr) minheap.push(temp);
        }
        return dummy->next;
    }
};
