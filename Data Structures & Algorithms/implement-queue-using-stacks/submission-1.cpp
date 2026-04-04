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
        if(t.empty()){
            while(!s.empty()){
                t.push(s.top());
                s.pop();
            }
        }
        int res = t.top();
        t.pop();
        return res;
    }
    
    int peek() {
        if(t.empty()){
            while(!s.empty()){
                t.push(s.top());
                s.pop();
            }
        }
        return t.top();
    }
    
    bool empty() {
        return s.empty() && t.empty();
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