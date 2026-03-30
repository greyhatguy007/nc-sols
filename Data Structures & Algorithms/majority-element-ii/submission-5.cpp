class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int a=INT_MAX,b=INT_MAX,ac=0,bc=0;
        for(int i : nums){
            if(i==a){
                ac++;
            } else if(i==b){
                bc++;
            } 
            else if(ac<=0){
                a=i;
                ac=1;
            } else if(bc<=0){
                b=i;
                bc=1;
            } else {
                ac--;
                bc--;
            }
        }
        ac=0,bc=0;
        for(int i : nums){
            if(i==a) ac++;
            if(i==b) bc++;
        }
        if(ac>nums.size()/3) ans.push_back(a);
        if(bc>nums.size()/3) ans.push_back(b);
        return ans;
    }
};