class MyCircularQueue {
public:
    struct node{
        node* prev;
        node* next;
        int val;
        node(int v, node* n=nullptr, node* p=nullptr) : val(v), prev(p), next(n) {}
    };

    int space;
    node* left;
    node* right;

    MyCircularQueue(int k) {
        space = k;
        left = new node(0);
        right = new node(0, nullptr, left);
        left -> next = right;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        node* cur = new node(value, right, right->prev);
        right->prev->next = cur;
        right->prev = cur;
        space--;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        node* tmp = left->next;
        left->next = left->next->next;
        left->next->prev = left;
        delete tmp;
        space++;
        return true;
    }
    
    int Front() {
        return isEmpty() ? -1 : left->next->val;
    }
    
    int Rear() {
        return isEmpty() ? -1 : right->prev->val;
    }
    
    bool isEmpty() {
        return left->next == right;
    }
    
    bool isFull() {
        return space==0;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */