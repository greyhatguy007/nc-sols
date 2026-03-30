class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        vector<int> presum(nums.size()+1);
        presum[0] = nums[0];
        for(int i=0;i<nums.size();i++) presum[i+1] = presum[i]+nums[i];
        for(int i=0;i<presum.size();i++){
            for(int j=i+1;j<presum.size();j++){
                if(presum[j]-presum[i]==k) ans++;
            }
        }
        return ans;
    }
};