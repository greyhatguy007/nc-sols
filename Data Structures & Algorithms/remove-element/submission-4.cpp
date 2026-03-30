class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()==0) return 0;
        int lo=0,hi=nums.size()-1;
        while(nums[hi]==val)hi--;
        while(lo<hi){
            if(nums[lo]==val) {
                swap(nums[lo],nums[hi]);
                lo++;
                while(nums[hi]==val)hi--;
            } else lo++;
        }
        return lo+(lo==hi);
    }
};