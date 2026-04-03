class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        map<int,int> mp;
        for(int i=0;i<k;i++) mp[nums[i]]++;
        ans.push_back(mp.rbegin()->first);
        int l=0;
        for(int r=k;r<nums.size();r++){
            mp[nums[r]]++;
            if(mp[nums[l]]==1) mp.erase(nums[l++]);
            else mp[nums[l++]]--;
            ans.push_back(mp.rbegin()->first);
        }
        return ans;
    }
};
