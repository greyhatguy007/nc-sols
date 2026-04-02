class Solution {
public:
    int minSubArrayLen(int x, vector<int>& nums) {
        int lo=0,hi=0,curr=0,ans=INT_MAX;
        while(hi<nums.size()){
            curr += nums[hi++];
            while(curr>=x) {
                ans = min(ans, hi-lo);
                curr = curr - nums[lo++];
            }
        }
        return (ans==INT_MAX) ? 0 : ans;
    }
};