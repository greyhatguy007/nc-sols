class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> q;
        vector<int> ans(n-k+1);
        for(int i=0;i<k;i++){
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
        }
        int l = 0;
        ans[l++] = nums[q.front()];
        for(int r=k;r<n;r++){
            while(!q.empty() && q.front()<l) q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[r]) q.pop_back();
            q.push_back(r);
            ans[l++] = nums[q.front()];
        }
        return ans;
    }
};
