class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            int key = target-nums[i];
            if(mp.find(nums[i])!=mp.end()) return {mp[nums[i]],i};
            mp[key] = i;
        }
        return {-1,-1};
    }
};
