class Solution {
public:
    bool ans(string s, int ctr) {
        int hi=s.size()-1,lo=0;
        while(lo<hi){
            if(s[hi]==s[lo]){
                hi--;
                lo++;
            } else {
                ctr++;
                if(ctr>1) return false;
                string l = s.substr(lo, hi-lo);
                string r = s.substr(lo+1, hi-lo);
                return ans(l, ctr) || ans(r,ctr);
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int ctr=0;
        return ans(s, ctr);
    }
};