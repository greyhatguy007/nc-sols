class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       int f=0,s=0;
       do {
        s = nums[s];
        f = nums[nums[f]];
       } while (f!=s);
       f = 0;
       do {
        f = nums[f];
        s = nums[s];
       } while(f!=s);
       return s;
    }
};
