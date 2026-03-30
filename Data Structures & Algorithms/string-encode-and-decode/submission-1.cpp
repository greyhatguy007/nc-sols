class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for(string w : strs){
            ans = ans + to_string(w.size());
            ans = ans+"#";
            ans = ans+w;
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int ptr=0;
        string length="";
        while(ptr<s.size()){
            if(s[ptr]=='#'){
                int len = stoi(length);
                string word = "";
                for(int i=ptr+1;i<ptr+1+len;i++) word = word+s[i];
                ans.push_back(word);
                length="";
                ptr = ptr+1+len;
            } else {
                length = length + s[ptr];
                ptr++;
            }
        }
        return ans;
    }
};
