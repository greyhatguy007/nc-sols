class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        int x[26]={0};
        for(char c : s) x[c-'a']++;
        for(char c : t) x[c-'a']--;
        for(int i : x) if(i!=0) return false;
        return true;
    }
};
