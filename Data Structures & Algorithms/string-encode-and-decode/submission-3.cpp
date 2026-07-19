class Solution {
public:

    string encode(vector<string>& strs) {
        if(strs.empty()) return "";
        string ans = "";
        for(string &s : strs){
            ans += to_string(s.size());
            ans += "#";
            ans += s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int ptr = 0;
        vector<string> ans;
        string sl = "";
        while(ptr<s.size()){
            if(s[ptr]=='#') {
                int len = stoi(sl);
                string word = "";
                for(int i=ptr+1;i<ptr+len+1;i++) word += s[i];
                ans.push_back(word);
                sl = "";
                ptr = ptr+1+len;
            } else {
                sl += s[ptr++];
            }
        }
        return ans;
    }
};
