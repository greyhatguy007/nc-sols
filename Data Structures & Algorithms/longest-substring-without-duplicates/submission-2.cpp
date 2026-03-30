class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lo=0,hi=0,ans=0;
        unordered_map<char,int> mp;
        while(hi<s.size()){
            if(mp.find(s[hi])!=mp.end())
                while(lo<=mp[s[hi]]) mp.erase(s[lo++]);
            mp[s[hi]] = hi;
            hi++;
            ans = max(ans, hi-lo);
        }
        return ans;
    }
};
