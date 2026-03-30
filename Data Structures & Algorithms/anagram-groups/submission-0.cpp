class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(string wrd : strs) {
            string srtd = wrd;
            sort(srtd.begin(), srtd.end());
            if(mp.find(srtd) != mp.end()){
                mp[srtd].push_back(wrd);
            } else {
                mp[srtd] = vector<string> {wrd};
            }
        }
        for(auto &[k, val] : mp) {
            ans.push_back(val);
        }
        return ans;
    }
};
