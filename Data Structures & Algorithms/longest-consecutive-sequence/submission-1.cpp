class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for(int i : nums) st.insert(i);
        int ans=0;
        int counter=0;
        for(int i : nums){
            if(st.find(i-1)!=st.end()) continue;
            while(st.find(i+counter)!=st.end()) counter++;
            ans = max(ans,counter);
            counter=0;
        }
        return ans;
    }
};
