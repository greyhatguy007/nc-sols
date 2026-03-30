class Solution {
public:

    bool checkRows(vector<vector<char>> &board){
        for(int i=0;i<9;i++){
            int bkt[9] = {0};
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                bkt[board[i][j]-'1']++;
            }
            for(int k : bkt) if(k>1) return false;
        }
        return true;
    }

    bool checkCols(vector<vector<char>> &board){
        for(int j=0;j<9;j++){
            int bkt[9] = {0};
            for(int i=0;i<9;i++){
                if(board[i][j]=='.') continue;
                bkt[board[i][j]-'1']++;
            }
            for(int k : bkt) if(k>1) return false;
        }
        return true;
    }

    bool checkGrids(vector<vector<char>> &board){
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                int bkt[9] = {0};
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.') continue;
                        bkt[board[k][l]-'1']++;
                    }
                }
                for(int m : bkt) if(m>1) return false;
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && checkGrids(board);
    }
};
