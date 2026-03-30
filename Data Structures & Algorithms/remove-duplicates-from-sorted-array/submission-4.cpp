class Solution {
public:
    int removeDuplicates(vector<int>& x) {
        int a=1;
        for(int b=1;b<x.size();b++) if(x[b]!=x[b-1]) x[a++] = x[b];
        return a;
    }
};