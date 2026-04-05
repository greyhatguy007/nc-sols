class Solution {
public:
    bool valid(unordered_map<char,int> &mp){
        for(pair<char,int> p : mp) if(p.second>0) return false;
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        pair<int,int> res = {-1,s.size()};
        for(char c : t) mp[c]++;
        int lo=0,hi=0;
        while(hi<s.size()){
            mp[s[hi]]--;
            while(valid(mp) && mp[s[lo]]<0) mp[s[lo++]]++;
            if(valid(mp) && (hi-lo < res.second-res.first)) res = {lo,hi};
            hi++;
        }
        cout << res.first << " " << res.second << endl;
        return (res.first==-1) ? "" : s.substr(res.first,res.second-res.first+1);
    }
};
