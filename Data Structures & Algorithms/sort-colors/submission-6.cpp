class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1=0,p2=nums.size()-1,p=0;
        while(p<=p2){
            if(nums[p]==1)p++;
            else if (nums[p]==0) swap(nums[p++],nums[p1++]);
            else swap(nums[p],nums[p2--]);     
        }
    }
};