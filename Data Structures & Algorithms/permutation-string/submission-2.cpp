class Solution {
public:
    bool all0(int bkt[]){
        for(int i=0;i<26;i++) if(bkt[i]!=0) return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int bkt[26] = {0};
        for(char c : s1) bkt[c-'a']++;
        int lo=0,hi=0;
        while(hi<=s2.size()){
            if(hi-lo<s1.size()) bkt[s2[hi++]-'a']--;
            else {
                if(all0(bkt)) return true;
                bkt[s2[lo++]-'a']++;
                bkt[s2[hi++]-'a']--;
            }
        }
        return false;  
    }
};
