class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<set<char>> row(9), col(9), box(9);
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                
                if(board[i][j] == '.') continue;
                
                char num = board[i][j];
                
                int boxIndex = (i/3)*3 + (j/3);
                
                if(row[i].count(num) || col[j].count(num) || box[boxIndex].count(num))
                    return false;
                
                row[i].insert(num);
                col[j].insert(num);
                box[boxIndex].insert(num);
            }
        }
        
        return true;
    }
};