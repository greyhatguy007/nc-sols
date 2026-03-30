class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string a = strs[0];
        string b = strs[strs.size()-1];
        string ans = "";
        int lim = min(a.size(), b.size());
        for(int i=0;i<lim;i++){
            if(a[i]==b[i]){
                ans = ans + a[i];
            } else {
                break;
            }
        }  
        return ans;
    }
};