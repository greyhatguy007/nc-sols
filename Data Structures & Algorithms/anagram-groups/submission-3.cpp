class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> mp;
        vector<int> cnt(26,0);
        for(string &s: strs){
            fill(cnt.begin(),cnt.end(),0);;
            for(char c : s) cnt[c-'a']++;
            mp[cnt].push_back(s);
        }
        vector<vector<string>> ans;
        for(pair<const vector<int>,vector<string>> &p : mp){
            ans.push_back(p.second);
        }
        return ans;
    }
};
