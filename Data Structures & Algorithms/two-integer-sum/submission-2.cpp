class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> cop;
        for(int i=0;i<nums.size();i++){
            cop.push_back({nums[i],i});
        }
        sort(cop.begin(), cop.end());
        int lo=0,hi=nums.size()-1;
        while(lo<hi){
            int curr = cop[lo].first+cop[hi].first;
            if(curr==target){
                if (cop[lo].second < cop[hi].second)
                    return {cop[lo].second, cop[hi].second};
                return {cop[hi].second, cop[lo].second};
            } else if (curr < target) {
                lo++;
            } else {
                hi--;
            }
        }
    }
};
