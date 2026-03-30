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
        map<pair<int,int>, unordered_set<int>> mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.') continue;
                int x = i/3, y=j/3;
                if(mp[{x,y}].find(board[i][j])!=mp[{x,y}].end()) return false;
                else mp[{x,y}].insert(board[i][j]);
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        return checkRows(board) && checkCols(board) && checkGrids(board);
    }
};
