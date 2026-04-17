class Solution {
public:
    int findpivot(vector<int> &x){
        int lo=0,hi=x.size()-1,mid;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(x[hi]>=x[mid]) hi = mid;
            else lo = mid + 1; 
        }
        return lo;
    }

    int findMin(vector<int> &nums) {
        int pivot = findpivot(nums);
        return nums[pivot];
    }
};
