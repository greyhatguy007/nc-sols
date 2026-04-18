class Solution {
public:
    int findpivot(vector<int> &x) {
        int lo=0,hi=x.size()-1,mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(x[mid]<=x[hi]) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    int search(vector<int>& x, int target) {
        int lo=0,hi=x.size()-1, pivot=findpivot(x), mid, rmid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            rmid = (mid + pivot) % x.size();
            if(x[rmid]<target) lo = mid + 1;
            else if(x[rmid]>target) hi = mid - 1;
            else return rmid;
        }
        return -1;
    }
};
