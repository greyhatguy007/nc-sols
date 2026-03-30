class Solution {
public:
    bool isPalindrome(string s) {
        int lo=0,hi=s.size()-1;
        while(lo<hi){
            char l = s[lo], h=s[hi];
            while(lo<s.size() && !((l>='A' && l<='Z') || (l>='a' && l<='z') || (l>='0' && l<='9'))){
                lo++;
                l=s[lo];
            }
            while(hi>0 && !((h>='A' && h<='Z') || (h>='a' && h<='z') || (h>='0' && h<='9'))){
                hi--;
                h=s[hi];
            }
            if(l>='A' && l<='Z') l = l + 'a'-'A';
            if(h>='A' && h<='Z') h = h + 'a'-'A';
            if(lo<=hi && l!=h) return false;
            lo++;
            hi--;
        }
        return true;
    }
};
