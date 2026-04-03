class Solution {
public:
    bool noPos(int bkt[]){
        for(int i=0;i<58;i++) if(bkt[i]>0) return false;
        return true;
    }
    string minWindow(string s, string t) {
        int lo=0,hi=0;
        string ans = "";
        int bkt[58] = {0};
        for(char c : t) bkt[c-'A']++;
        while(hi<s.size()){
            bkt[s[hi++]-'A']--;
            if(noPos(bkt)){
                while(noPos(bkt) && bkt[s[lo]-'A']<0) bkt[s[lo++]-'A']++;
                if(ans.empty() || hi-lo<ans.size()) ans = s.substr(lo, hi-lo);
            }
        }
        return ans;
    }
};
