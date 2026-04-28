class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int key = nums[i]>0 ? nums[i] : -nums[i];
            if(nums[key]<0) return key;
            nums[key] *= -1;
        }
        return 0;
    }
};
