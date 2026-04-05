class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> wm, tm;
        for(char c : t) tm[c]++;
        int lo=0,hi=0,seen=0,need=tm.size(),reslen=INT_MAX;
        pair<int,int> res = {-1,-1};
        while(hi<s.size()){
            wm[s[hi]]++;
            if(tm.count(s[hi]) && wm[s[hi]]==tm[s[hi]]) seen++;
            while(seen==need) {
                if(hi-lo+1<reslen){ 
                    res = {lo,hi};
                    reslen = hi-lo+1;
                }
                wm[s[lo]]--;
                if(tm.count(s[lo]) && wm[s[lo]]<tm[s[lo]]) seen--;
                lo++;
            }
            hi++;
        }
        return reslen==INT_MAX ? "" : s.substr(res.first,reslen);
    }
};
