class Solution {
public:
    bool isPalin(string &s, int lo, int hi, int cnt){
        if(cnt>1) return false;
        while(lo<hi){
            if(s[lo]==s[hi]){
                lo++;
                hi--;
            } else {
                return isPalin(s,lo+1,hi,cnt+1) || isPalin(s,lo,hi-1,cnt+1);
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        return isPalin(s,0,s.size()-1,0);
    }
};