class Solution {
public:
    int removeDuplicates(vector<int>& x) {
        int a=0,b=0;
        while(b<x.size()){
            while(x[b]==x[b+1]) b++;
            x[a] = x[b];
            a++;
            b++;
        }
        return a;
    }
};