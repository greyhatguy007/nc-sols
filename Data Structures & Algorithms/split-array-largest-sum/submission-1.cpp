class Solution {
public:
    int getkfromsum(vector<int> &nums, int s){
        int k = 1,curr=0;
        for(int &i : nums){
            if(curr+i>s){
                k++;
                curr = 0;
            }
            curr += i;
        }
        return k;
    }

    int splitArray(vector<int>& nums, int k) {
        int lo=0,hi=0,mid,curr,ans;
        for(int &i : nums){
            lo = max(lo,i);
            hi+=i;
        }
        while(lo<=hi) {
            mid = lo + (hi-lo)/2;
            cout << lo << " " << mid << " " << hi << endl;
            curr = getkfromsum(nums,mid);
            if(curr<=k){
                ans = mid;
                hi = mid - 1;
            }
            else if(curr>k) lo = mid + 1;
        }
        return ans;
    }
};