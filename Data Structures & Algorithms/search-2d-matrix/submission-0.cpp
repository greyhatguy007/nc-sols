class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rmin=0,rmax=matrix.size()-1,rmid,rans=-1;
        while(rmin<=rmax){
            rmid = rmin + (rmax-rmin)/2;
            if(matrix[rmid][matrix[0].size()-1]<target) rmin = rmid + 1;
            else if(matrix[rmid][0]>target) rmax = rmid - 1;
            else {
                rans = rmid;
                break;
            }
        }
        if(rans==-1) return false;
        int cmin=0,cmax=matrix[0].size()-1, cmid,curr;
        while(cmin<=cmax){
            cmid = cmin + (cmax-cmin)/2;
            curr = matrix[rans][cmid];
            if(curr<target) cmin = cmid + 1;
            else if(curr>target) cmax = cmid - 1;
            else return true;
        }
        return false;
    }
};
