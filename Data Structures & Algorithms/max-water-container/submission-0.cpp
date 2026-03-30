class Solution {
public:
    int maxArea(vector<int>& x) {
        int lo=0,hi=x.size()-1, ans=0;
        while(lo<hi){
            ans = max(ans, min(x[hi],x[lo])*(hi-lo));
            if(x[hi]>x[lo]) lo++;
            else hi--;
        }
        return ans;
    }
};
