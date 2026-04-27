/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map<Node*,Node*> mp;

    void insert(Node* o, Node* n){
        n -> val = o->val;
        mp[o] = n;
        Node* newnode = new Node(0);
        if(o->next==nullptr){
            n->random = mp[o->random];
            return;
        }        
        n -> next = newnode;
        insert(o->next, newnode);
        n -> random = mp[o->random];
    }


    Node* copyRandomList(Node* head) {
        if(head==nullptr) return head;
        Node *nhead = new Node(0);
        insert(head, nhead);
        return nhead;
    }
};
