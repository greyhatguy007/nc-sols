class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n[3] = {0};
        for(int i : nums) n[i]++;
        int ptr=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<n[i];j++){
                nums[ptr] = i;
                ptr++;
            }
        }
    }
};