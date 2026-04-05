class Solution {
public:
    bool valid(unordered_map<char,int> &mp){
        for(pair<char,int> p : mp) if(p.second>0) return false;
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char,int> mp;
        string ans = "";
        for(char c : t) mp[c]++;
        int lo=0,hi=0;
        while(hi<s.size()){
            mp[s[hi]]--;
            while(valid(mp) && mp[s[lo]]<0) mp[s[lo++]]++;
            if(valid(mp) && (ans.empty() || hi-lo<ans.size())) ans = s.substr(lo,hi-lo+1);
            hi++;
        }
        return ans;
    }
};
