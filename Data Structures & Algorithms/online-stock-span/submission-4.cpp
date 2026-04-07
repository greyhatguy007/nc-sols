class StockSpanner {
public:
    stack<pair<int,int>> st;
    int ctr;
    StockSpanner() {
        ctr=0;
    }
    
    int next(int price) {
        int ans;
        while(!st.empty() && st.top().first <= price) st.pop();
        if(st.empty()) ans =  ctr+1;
        else ans = ctr-st.top().second;
        st.push({price,ctr});
        ctr++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */