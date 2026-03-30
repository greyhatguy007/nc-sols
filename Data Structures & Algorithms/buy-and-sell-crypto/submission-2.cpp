class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, mi=prices[0];
        for(int i : prices){
            ans = max(ans, i-mi);
            mi = min(mi,i);
        }
        return ans;
    }
};
