class NumMatrix {
public:
    vector<vector<int>> x;
    NumMatrix(vector<vector<int>>& m) {
        int rows = m.size(), cols = m[0].size();
        x = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
        for(int i=1;i<=rows;i++){
            int runsum = 0;
            for(int j=1;j<=cols;j++){
                runsum += m[i-1][j-1];
                x[i][j] = x[i-1][j] + runsum;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return x[r2+1][c2+1] - x[r1][c2+1] - x[r2+1][c1] + x[r1][c1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */