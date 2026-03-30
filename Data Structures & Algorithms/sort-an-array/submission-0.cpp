class Solution {
public:
    vector<int> sortArray(vector<int>& arr) {
        vector<int> ans = mergeSort(arr);
        return ans;
    }

    vector<int> mergeSort(vector<int> &arr){
        if(arr.size()<=1) return arr;
        int mid = arr.size()/2;
        vector<int> left(arr.begin(), arr.begin() + mid);
        vector<int> right(arr.begin() + mid, arr.end());
        left = mergeSort(left);
        right = mergeSort(right);
        vector<int> ans = merge(left,right);
        return ans;
    }

    vector<int> merge(vector<int> &a, vector<int> &b){
        vector<int> ans;
        int x=0,y=0;
        while(x<a.size()&&y<b.size()){
            if(a[x]<b[y]) ans.push_back(a[x++]);
            else ans.push_back(b[y++]);
        }
        while(x<a.size()) ans.push_back(a[x++]);
        while(y<b.size()) ans.push_back(b[y++]);
        return ans;
    }
};