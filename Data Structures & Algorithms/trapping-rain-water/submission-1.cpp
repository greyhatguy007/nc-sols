class Solution {
public:
    int trap(vector<int>& x) {
        int ans=0;
        vector<int> r(x.size()),l(x.size());
        l[0] = 0;r[x.size()-1]=0;
        for(int i=1;i<x.size();i++) l[i] = max(l[i-1],x[i-1]);
        for(int i=x.size()-2;i>=0;i--) r[i] = max(r[i+1],x[i+1]);
        for(int i=0;i<l.size();i++){
            int k = min(l[i],r[i]);
            if(k>x[i]) ans += k-x[i];
        }
        return ans;
    }
};
