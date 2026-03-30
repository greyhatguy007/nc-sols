class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int s=0,lo=0,hi=numbers.size()-1;
        while(hi>lo){
            s = numbers[hi]+numbers[lo];
            if(s==target) return {lo+1,hi+1};
            if(s>target) hi--;
            else lo++;
        } 
        return {-1,-1};
    }
};
