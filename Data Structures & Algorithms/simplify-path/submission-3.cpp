class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int l=0,r=0, n=path.size();
        string tmp;
        while(r<n){
            if(path[r]=='/'){
                if(l!=r){
                    tmp = path.substr(l,r-l);
                    if(tmp==".." && !st.empty()) st.pop();
                    else if(tmp!="." && tmp!="..") st.push(tmp);
                }
                l = ++r;
            } else r++;
        }
        tmp = path.substr(l,r-l);
        if(tmp==".." && !st.empty()) st.pop();
        else if(tmp!="." && tmp!=".." && r!=l) st.push(tmp);
        
        tmp = "";
        while(!st.empty()) {
            tmp = "/"+st.top()+tmp;
            st.pop();
        }
        return tmp=="" ? "/" : tmp;
    }
};