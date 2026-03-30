class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==1) return strs[0];
        string prev = strs[0];
        int j;
        for(int i=1;i<strs.size();i++){
            for(j=0;j<min(prev.size(), strs[i].size());j++){
                if(prev[j]!=strs[i][j]) break;
            }
            prev = prev.substr(0,j);
        }
        return prev;
    }
};