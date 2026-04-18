class Solution {
public:
    int findpivot(vector<int> &x) {
        int lo=0,hi=x.size()-1,mid;
        if(x[lo]<x[hi]) return 0;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            cout << lo << " " << mid << " " << hi << endl; 
            if(x[lo]<x[mid]) lo = mid;
            else if(x[lo]>x[mid]) hi = mid;
            else lo++;
        }
        return hi;
    }

    bool search(vector<int>& x, int target) {
        int lo=0,hi=x.size()-1, pivot=findpivot(x), mid, rmid;
        cout << pivot << endl;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            rmid = (mid + pivot) % x.size();
            if(x[rmid]<target) lo = mid + 1;
            else if(x[rmid]>target) hi = mid - 1;
            else return true;
        }
        return false;
    }
};
