class Solution {
public:
    int helper(vector<int> &w, int weight){
        int days = 1,cursum=0;
        for(int i : w) {
            if(cursum+i>weight) {
                days++;
                cursum=0    ;
            } 
            cursum +=i;
        }
        return days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int lo=1,hi=0,mid;
        for(int i : weights) {hi+=i; lo = max(lo,i);}
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(helper(weights,mid)<=days)hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};