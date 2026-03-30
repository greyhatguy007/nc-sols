class Solution {
public:
    int trap(vector<int>& x) {
        int lo=0,hi=x.size()-1;
        int maxl=x[lo],maxr=x[hi];
        int ans = 0;
        while(lo<hi){
            maxl = max(maxl, x[lo]);
            maxr = max(maxr, x[hi]);
            if(maxl<maxr){
                ans+=maxl-x[lo];
                lo++;
            } else {
                ans+=maxr-x[hi];
                hi--;
            }
        }
        return ans;
    }
};
