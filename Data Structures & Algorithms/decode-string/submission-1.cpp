class Solution {
public:
    string decodeString(string s) {
        int k = 0;
        stack<char> st;
        while(k<s.size()){
            if(s[k]==']') {
                string t="",n="",rep="";
                while(!st.empty() && st.top() != '[') {
                    t = st.top()+t;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                while(!st.empty() && st.top()<='9' && st.top()>='0'){
                n = st.top()+n;
                    st.pop();
                }
                int nn = stoi(n);
                while(nn--) {
                    int lo = 0;
                    while(lo<t.size()) st.push(t[lo++]);
                }
            } else st.push(s[k]);
            k++;
        }   
        string ans = "";
        while(!st.empty()){
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};