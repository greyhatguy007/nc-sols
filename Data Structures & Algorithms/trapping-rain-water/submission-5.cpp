class Solution {
public:
    int trap(vector<int>& x) {
        int lo=0,hi=x.size()-1,maxL=x[lo],maxR=x[hi],ans=0;
        while(lo<hi){
            if(x[lo]<x[hi]){
                int diff = min(maxL, maxR) - x[lo];
                if(diff>0) ans+=diff; 
                maxL = max(maxL, x[++lo]);
            }  else {
                int diff = min(maxL, maxR) - x[hi];
                if(diff>0) ans+=diff;
                maxR = max(maxR, x[--hi]);
            }
        }
        return ans;
    }
};
