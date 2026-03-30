class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> k;
        for(int i=0;i<nums.size()-1;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int lo=i+1,hi=nums.size()-1,target;
            while(lo<hi){
                target = nums[lo]+nums[i]+nums[hi];
                if(target==0){
                    k.push_back({nums[lo],nums[i],nums[hi]});
                    lo++;
                    hi--;
                    while(nums[lo]==nums[lo-1]) lo++;
                    while(nums[hi]==nums[hi+1]) hi--;
                    
                } else if (target>0) {
                    hi--;
                } else {
                    lo++;
                }
            }
        }
        return k;
    }
};
