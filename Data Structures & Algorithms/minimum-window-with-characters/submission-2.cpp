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


// 0  A
// 1  B
// 2  C 
// 3  D 
// 4  E
// 5  F
// 6  G
// 7  H
// 8  I
// 9  J
// 10 K
// 11 L
// 12 M 
// 13 N 
// 14 O 
// 15 P
// 16 Q
// 17 R
// 18 S
// 19 T 
// 20 U 
// 21 V
// 22 W 
// 23 X 1
// 24 Y 1
// 25 Z 1