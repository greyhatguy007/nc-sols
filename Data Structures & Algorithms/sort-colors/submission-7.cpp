class Solution {
public:
    void sortColors(vector<int>& nums) {
        int beg=0, end=nums.size()-1, ptr=0;
        while(ptr<=end){
            if(nums[ptr]==1) ptr++;
            else if(nums[ptr]==0) swap(nums[ptr++],nums[beg++]);
            else swap(nums[ptr],nums[end--]);
        }
        return;
    }
};