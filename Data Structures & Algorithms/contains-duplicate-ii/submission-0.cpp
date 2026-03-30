class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int lo=0,hi=1;
        while(lo<nums.size() && hi<nums.size()){
            if(hi-lo>k){
                lo++;
                hi = lo+1;
            } else {
                if(nums[hi]==nums[lo]) return true;
                hi++;
            }
        }
        return false;
    }
};