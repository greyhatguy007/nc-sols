class Solution {
public:
    string decodeString(string s) {
        stack<string> st;

        for(char &c : s) {
            if(c!=']') st.push(string(1,c));
            else {
                string curr="", nn="", rep="";
                while(!st.empty() && st.top()!="[") {
                    curr = st.top()+curr;
                    st.pop();
                }
                if(!st.empty()) st.pop();
                while(!st.empty() && st.top()>="0" && st.top()<="9"){
                    nn = st.top()+nn;
                    st.pop();
                }
                int n = stoi(nn);
                while(n--) rep+=curr;
                st.push(rep);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans = st.top()+ans;
            st.pop();
        }
        return ans;
    }
};