class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ma=nums[0], na=1, nb=0, mb=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==ma) na++;
            else if (nums[i]==mb) nb++;
            else {
                mb = nums[i];
                nb = 1;
            }
            if(nb>na){
                swap(na,nb);
                swap(ma,mb);
            }
        }
        return ma;
    }
};