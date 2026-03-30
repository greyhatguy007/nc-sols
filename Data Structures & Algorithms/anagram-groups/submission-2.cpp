class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(const string &wrd : strs) {
            vector<int> cnt(26,0);
            string key = "";
            for(const char &c : wrd) cnt[c-'a']++;
            for(const int i : cnt) key+=to_string(i)+",";
            mp[key].push_back(wrd); 
        }
        for(const pair p : mp) ans.push_back(p.second);
        return ans;
    }
};
