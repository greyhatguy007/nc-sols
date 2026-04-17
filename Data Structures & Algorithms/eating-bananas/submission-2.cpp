class Solution {
public:
    int helper(vector<int>& piles, int rate){
        int ans = 0;
        for(int i : piles){
            if(i<rate) ans++;
            else ans += i/rate + (i%rate>0);

        }
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long unsigned int lo = 1, hi = 0, mid,ans=0;
        for(int i : piles) hi += i;
        while(lo<hi) {
            mid = lo + (hi-lo)/2;
            if(helper(piles,mid)<=h){
                ans = mid;
                hi = mid;
            } else lo = mid + 1;
        }
        return ans;
    }
};
