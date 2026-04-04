class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st,x;
        for(int i : asteroids) {
            if(st.empty()) st.push(i);
            else if(i<0 && st.top()>0) {
                while(!st.empty() && abs(st.top())<abs(i) && i<0 && st.top()>0) {
                    st.pop();
                } 
                if (!st.empty() && abs(st.top())==abs(i) && i<0 && st.top()>0 ){
                    st.pop();
                } else if(st.empty() || (!st.empty() && abs(st.top()<abs(i)))){
                    st.push(i);
                }
                
            } else {
                st.push(i);
            }
        }
        vector<int> ans(st.size());
        for(int i=st.size()-1;i>=0;i--){
            ans[i] = st.top();
            st.pop();
        }
        return ans;
    }
}; 