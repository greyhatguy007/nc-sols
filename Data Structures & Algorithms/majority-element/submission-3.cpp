class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int ctr=0,maj=-1;
       for(int i:nums){
        if(i==maj) ctr++;
        else ctr--;
        if(ctr<0){
            maj=i;
            ctr=1;
        }
       } 
       return maj;
    }
};