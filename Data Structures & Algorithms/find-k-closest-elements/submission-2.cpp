class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo=0,hi=arr.size()-1;
        while(hi-lo>=k){
            int a = abs(x-arr[lo]);
            int b = abs(x-arr[hi]);
            if(a<=b) hi--;
            else lo++;
        }
        vector<int> ans;
        for(int i=lo;i<=hi;i++) ans.push_back(arr[i]);
        return  ans;
    }
};