class MyQueue {
public:
    stack<int> s;
    stack<int> t;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int res;
        while(!s.empty()){
            res = s.top();
            t.push(res);
            s.pop();
        }
        t.pop();
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
        return res;
    }
    
    int peek() {
        int res;
        while(!s.empty()){
            res = s.top();
            t.push(res);
            s.pop();
        }
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
        return res;
    }
    
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */