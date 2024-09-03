class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true; 
    }
    void BackTrack(vector<string>& board, int col, vector<vector<string>>& ans) {
        int n = board.size();
        if (col == n) { 
            ans.push_back(board); 
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q'; 
                BackTrack(board, col + 1, ans); 
                board[row][col] = '.'; 
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans ;
        vector<string> board(n, string(n, '.'));    
        BackTrack(board, 0, ans);
        return ans; 
    }
};