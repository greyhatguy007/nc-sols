class Solution {
public:
    vector<int> NSL(vector<int> a) {
        int n = a.size();
        vector<int> ans(a);
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first>=a[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top().second;
            st.push({a[i],i});
        }
        return ans;
    }

    vector<int> NSR(vector<int> a) {
        int n = a.size();
        vector<int> ans(a);
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first>=a[i]) st.pop();
            ans[i] = st.empty() ? n : st.top().second;
            st.push({a[i],i});
        }
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nsr = NSR(heights);
        vector<int> nsl = NSL(heights);
        int ans = 0;
        for(int i=0;i<heights.size();i++){
            ans = max(ans, heights[i]*(nsr[i]-nsl[i]-1));
        }
        return ans;
    }
};
