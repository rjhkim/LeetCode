class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //reverse thinking
        int rows = board.size();
        int col = board[0].size();


        //1. (DFS) capture unsurrounded regions (0 -> t)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O' && ((i == 0 || i == rows - 1) || 
                (j == 0 || j == col - 1))) {
                    capture(i, j, rows, col, board);
                }
            }
        }

        //2. (for loops )capture the surrounded regions (double for loop change O -> x)
         for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
         }

        
        //3. uncapture the unsurrounded regions (t -> 0)
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
         }

    }

    void capture (int r, int c, int rows, int col, vector<vector<char>>& board) {
        if (r < 0 || c < 0 || r == rows || c == col || board[r][c] != 'O') {
            return;
        }

        board[r][c] = 'T';
        capture(r + 1, c, rows, col, board);
        capture(r, c + 1, rows, col, board);
        capture(r, c - 1, rows, col, board);
        capture(r - 1, c, rows, col, board);
    }
};