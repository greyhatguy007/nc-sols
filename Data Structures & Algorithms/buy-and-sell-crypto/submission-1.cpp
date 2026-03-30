class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=prices[0],ma=prices[0],ans=0;
        for(int i : prices){
            if(i > ma){
                ans = max(ans,i - mi);
                ma = i;
            } else if (i<mi){
                mi = i;
                ma = i;
            }

        } 
        return ans;
    }
};
