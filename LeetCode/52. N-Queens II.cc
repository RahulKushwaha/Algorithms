class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool> (n, false));
        int output = 0;
        nQueens(board, 0, output);
        
        return output;
    }
    
    bool isAllowed(vector<vector<bool>>& board, int r, int c)
    {
        for(int j = c; j >= 0; j --)
        {
            if(board[r][j])
            {
                return false;
            }
        }
        
        for(int i = r; i >= 0; i --)
        {
            if(board[i][c])
            {
                return false;
            }
        }
        
        for(int i = r, j = c; i >= 0 && j >= 0; i -- , j --)
        {
            if(board[i][j])
            {
                return false;
            }
        }
        
        for(int i = r, j = c; i >= 0 && j < board.size(); i --, j ++)
        {
            if(board[i][j])
            {
                return false;
            }
        }
        
        return true;
    }
    
    void nQueens(vector<vector<bool>>& board, int row, int&  output)
    {
        int n = board.size();
        if(row > n)
        {
            return;
        }
        
        if(row == n)
        {
            output++;
            return;
        }

        for(int j = 0; j < n; j ++)
        {
            if(isAllowed(board, row, j))
            {
                board[row][j] = true;
                nQueens(board, row + 1, output);
                board[row][j] = false;
            }
        }
    }
};