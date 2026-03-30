class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int bkt[2002] = {0};
        vector<int> freq[nums.size()+1];
        for(int i : nums) bkt[i+1000]++;
        for(int i=0;i<2002;i++){
            if(bkt[i]!=0){
                freq[bkt[i]].push_back(i-1000);
            }
        }
        for(int i=nums.size();i>=0;i--){
            if(freq[i].empty()) continue;
            for(int j : freq[i]){
                ans.push_back(j);
                k--;
                if(k==0) return ans;
            }
        }
        return ans;
    }
};
