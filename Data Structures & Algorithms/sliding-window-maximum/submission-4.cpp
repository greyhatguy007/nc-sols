class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size(),l=0,r=0;
        deque<int> q;
        vector<int> ans(n-k+1);
        while(r<n){
            while(!q.empty() && nums[q.back()]<nums[r]) q.pop_back();
            q.push_back(r);
            if(l>q.front()) q.pop_front();
            if(r-l+1>=k){
                ans[l] = nums[q.front()];
                l++;
            }
            r++;
        }
        return ans;
    }
};
