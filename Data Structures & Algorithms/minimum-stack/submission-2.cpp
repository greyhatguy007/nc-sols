class MinStack {
    stack<int> s;
    stack<int> t;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        s.push(val);
        if(t.empty() || val <= t.top()) t.push(val);
    }
    
    void pop() {
        int val = s.top();
        if(t.top()==val) t.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return t.top();
    }
};
