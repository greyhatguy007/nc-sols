class Solution {
public:
    int numRescueBoats(vector<int>& x, int limit) {
        int lo=0,hi=x.size()-1, ans=0;
        sort(x.begin(),x.end());
        while(lo<=hi){
            if(x[hi]+x[lo]<=limit){
                lo++;
                hi--;
                ans++;
            // } else if(x[lo]+x[lo+1]<=limit){
            //     lo+=2;
            //     ans++;
            } else {
                hi--;
                ans++;
            }
            
        }
        return ans;
    }
};