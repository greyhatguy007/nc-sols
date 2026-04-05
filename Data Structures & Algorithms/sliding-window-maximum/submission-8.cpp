class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> maxheap;
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<k;i++) maxheap.push({nums[i],i});
        int l = 1;
        ans.push_back(maxheap.top().first);
        for(int r=k;r<n;r++){
            while(!maxheap.empty() && maxheap.top().second < l) maxheap.pop();
            maxheap.push({nums[r],r});
            ans.push_back(maxheap.top().first);
            l++;
        }
        return ans;
    }
};
