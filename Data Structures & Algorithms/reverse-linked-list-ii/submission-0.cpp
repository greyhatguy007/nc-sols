class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;
        ListNode dummy(0, head);
        ListNode* prev = &dummy;
        for (int i = 1; i < left; ++i) {
            prev = prev->next;
        }
        ListNode* sublistHead = prev->next;
        ListNode* sublistTail = sublistHead;
        for (int i = left; i < right; ++i) {
            sublistTail = sublistTail->next;
        }
        ListNode* after = sublistTail->next; 
        sublistTail->next = nullptr;
        auto [newHead, newTail] = reverse(sublistHead);
        prev->next = newHead;      
        newTail->next = after;     
        return dummy.next;     
    }

private:
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return {prev, head};
    }
};