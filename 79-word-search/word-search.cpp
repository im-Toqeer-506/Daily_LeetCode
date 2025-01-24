class Solution {
public:
    bool find(vector<vector<char>>& board, int row, int col, int idx, string& word) {
        if (idx == word.length())
            return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() ||board[row][col]=='$'|| board[row][col] != word[idx])
            return false;

        char temp = board[row][col];
        board[row][col] = '$'; 

        
        bool found = find(board, row + 1, col, idx + 1, word) || 
                     find(board, row - 1, col, idx + 1, word) ||
                     find(board, row, col + 1, idx + 1, word) || 
                     find(board, row, col - 1, idx + 1, word);   

        board[row][col] = temp; 
        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                return true;
            }
        }
    }
        return false;
    }
};