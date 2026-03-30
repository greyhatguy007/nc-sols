class Solution {
public:

    string encode(vector<string>& strs) {
        string ans="";
        for(string word : strs){
            for(char c : word){
                ans = ans + to_string(static_cast<int>(c));
                ans = ans + ",";
            }
            ans = ans + ".";
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        string curr = "", asci="";
        int lo=0,hi=0;
        while(lo<s.size() && hi<s.size()){
            if(s[hi]=='.'){
                ans.push_back(curr);
                curr = "";
                hi++;
                lo=hi; 
            } else if (s[hi]==','){
                curr = curr+static_cast<char>(stoi(asci));
                asci="";
                hi++;
                lo=hi;
            } else {
                asci = asci+s[hi];
                hi++;
            }
        }
        return ans;
    }
};
