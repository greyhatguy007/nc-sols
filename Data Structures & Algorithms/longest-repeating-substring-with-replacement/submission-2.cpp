class Solution {
public:
    pair<int,int> hlpr(int bkt[]){
        int maxCnt=0, othrCnt=0;
        for(int i=0; i<26; i++){
            othrCnt += bkt[i];
            maxCnt = max(bkt[i], maxCnt);
        }
        othrCnt -= maxCnt;
        return {maxCnt, othrCnt};
    }

    int characterReplacement(string s, int k) {
        int bkt[26]={0};
        int lo=0,hi=0,ans=0;
        while(hi<s.size()){
            bkt[s[hi++]-'A']++;
            auto [maxCnt, othrCnt] = hlpr(bkt);
            if(othrCnt<=k) ans = max(ans, othrCnt+maxCnt);
            else {
                while(othrCnt>k) {
                    bkt[s[lo++]-'A']--;
                    tie(maxCnt, othrCnt) = hlpr(bkt);
                }
            } 
        }
        return ans;
    }
};
