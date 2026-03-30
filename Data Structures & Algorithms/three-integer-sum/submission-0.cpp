class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<vector<int>> k;
        for(int i=0;i<nums.size()-1;i++){
            int lo=i+1,hi=nums.size()-1,target;
            while(lo<hi){
                target = nums[lo]+nums[i]+nums[hi];
                if(target==0){
                    if(i!=lo && i!=hi && lo!=hi){
                        ans.insert({nums[lo],nums[i],nums[hi]});
                        lo++;
                        hi--;
                    }
                } else if (target>0) {
                    hi--;
                } else {
                    lo++;
                }
            }
        }
        for(vector<int> v : ans) k.push_back(v);
        return k;
    }
};
