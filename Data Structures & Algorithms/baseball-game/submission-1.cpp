class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;
        for(string c : operations){
            if(c=="C"){
                if(!st.empty()) {
                    ans -= st.top();
                    st.pop();
                }
            } else if (c=="D") {
                if(!st.empty()) st.push(st.top()*2);
                ans += st.top();
            } else if (c=="+") {
                if(st.size()>1){
                    int x = st.top();
                    st.pop();
                    int res = st.top()+x;
                    st.push(x);
                    st.push(res);
                    ans += st.top();
                }
            } else {
                st.push(stoi(c));
                ans += st.top();
            }
        }
        return ans;
    }
};