class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board;
        for(int i = 0; i < n; i ++)
        {
            vector<bool> row;
            row.resize(n);
            board.push_back(row);
            
            for(int j = 0; j < n; j ++)
            {
                board[i][j] = false;
            }
        }

        vector<vector<string>> output;
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
    
    void setOutput(vector<vector<string>> & output, vector<vector<bool>>& board)
    {
        vector<string> currentOutput;
        for(int i = 0; i < board.size(); i ++)
        {   
            string row;
            for(int j = 0; j < board.size(); j ++)
            {
                if(board[i][j])
                {
                    row += 'Q';
                }
                else
                {
                    row += '.';
                }
            }

            currentOutput.push_back(row);
        }
        
        output.push_back(currentOutput);
    }
    
    void nQueens(vector<vector<bool>>& board, int row, vector<vector<string>> &  output)
    {
        int n = board.size();
        if(row > n)
        {
            return;
        }
        
        if(row == n)
        {
            setOutput(output, board);
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