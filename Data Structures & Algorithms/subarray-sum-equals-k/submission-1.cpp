class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        vector<int> presum(nums.size()+1);
        unordered_map<int,int> mp;
        presum[0] = nums[0];
        for(int i=0;i<nums.size();i++) presum[i+1] = presum[i]+nums[i];
        for(int i : presum){
            ans += mp[i];
            mp[k+i]++;
        }
        return ans;
    }
};