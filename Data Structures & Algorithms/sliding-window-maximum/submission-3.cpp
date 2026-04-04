class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> ans(n-k+1);
        int l=0,r=0;
        while(r<n){
            while(!q.empty() && nums[q.back()]<nums[r]) q.pop_back();
            q.push_back(r);
            if(l>q.front()) q.pop_front();
            if((r+1)>=k){
                ans[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return ans;
    }
};
