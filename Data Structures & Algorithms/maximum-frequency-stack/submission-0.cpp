class FreqStack {
public:
    map<int,int> freq;
    map<int, stack<int>> res;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        res[freq[val]].push(val);
    }
    
    int pop() {
        int ans = res.rbegin()->second.top();
        freq[ans]--;
        res.rbegin()->second.pop();
        if(res.rbegin()->second.empty()) res.erase(res.rbegin()->first);
        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */