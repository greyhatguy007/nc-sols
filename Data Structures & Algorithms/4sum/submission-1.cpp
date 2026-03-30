class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1;j<nums.size();j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int lo=j+1, hi=nums.size()-1;
                long long int s;
                while(lo<hi){
                    s = (long long int) nums[i]+nums[j]+nums[lo]+nums[hi];
                    if(s==target){
                        ans.push_back({nums[i],nums[j],nums[lo],nums[hi]});
                        lo++;
                        hi--;
                        while(lo < hi && nums[lo]==nums[lo-1]) lo++;
                        while(lo < hi && nums[hi]==nums[hi+1]) hi--;
                    } else if (s<target){
                        lo++;
                    } else {
                        hi--;
                    }
                }
            }
        }
        return ans;
    }
};