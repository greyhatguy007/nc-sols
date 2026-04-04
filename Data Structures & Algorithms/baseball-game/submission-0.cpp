class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int ans = 0;
        for(string c : operations){
            if(c=="C"){
                if(!st.empty()) st.pop();
                else continue;
            } else if (c=="D") {
                if(!st.empty()) st.push(st.top()*2);
                else continue;
            } else if (c=="+") {
                if(st.size()>1){
                    int x = st.top();
                    st.pop();
                    int res = st.top()+x;
                    st.push(x);
                    st.push(res);
                }
            } else {
                st.push(stoi(c));
            }
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};