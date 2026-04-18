class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        if(m>n) return findMedianSortedArrays(b,a);
        int lo=0,hi=m,mid, bmid, l1,l2,r1,r2;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            bmid = (m+n)/2 - mid;
            l1 = (mid==0) ? INT_MIN : a[mid-1];
            r1 = (mid==m) ? INT_MAX : a[mid];
            l2 = (bmid==0) ? INT_MIN : b[bmid-1];
            r2 = (bmid==n) ? INT_MAX : b[bmid];
            if(l2>r1) lo = mid + 1;
            else if(l1>r2) hi = mid - 1;
            else break;
        }
        if((m+n)&1) return min(r1,r2);
        else return (double)(max(l1,l2)+min(r1,r2))/2;
    }
};
