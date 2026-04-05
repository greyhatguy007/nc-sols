class Solution {
public:
    bool valid(int bkt[]){
        for(int i=0;i<80;i++) if(bkt[i]>0) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int bkt[80] = {0};
        string ans = "";
        for(char c : t) bkt[c-'A']++;
        int lo=0,hi=0;
        while(hi<s.size()){
            bkt[s[hi]-'A']--;
            while(valid(bkt) && bkt[s[lo]-'A']<0) bkt[s[lo++]-'A']++;
            if(valid(bkt) && (ans.empty() || hi-lo < ans.size())) ans = s.substr(lo, hi-lo+1);
            hi++;
        }
        return ans;
    }
};
