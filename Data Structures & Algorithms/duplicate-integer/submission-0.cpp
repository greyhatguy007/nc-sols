class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums){
            auto it = mp.find(i);
            if(it != mp.end()) return true;
            mp[i] = 1; 
        }
        return false;
    }
};