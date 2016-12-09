class Solution {
public:
    bool rows[9][9] = {{0}};
    bool cols[9][9] = {{0}};
    bool units[9][9] = {{0}};
    
     void solveSudoku(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i ++)
        {
            for(int j = 0; j < 9; j ++)
            {
                int unitIndex = (i / 3) * 3 + (j / 3);
                int val = board[i][j] - '1';
                
                if(board[i][j] != '.')
                {
                    rows[i][val] = true;
                    cols[j][val] = true;
                    units[unitIndex][val] = true;
                }
            }
        }
        
        solveSudoku(board, 0, 0, 0);
    }
    
    bool solveSudoku(vector<vector<char>>& board, int x, int y, int index)
    {
        if(index == 81)
        {
            return true;   
        }
        
        if(y == 9)
        {
            x ++;
            y = 0;
        }
        
        char& ch = board[x][y];
        if(ch != '.')
        {
            return solveSudoku(board, x, y + 1, index + 1);
        }
        
        for(int i = 0; i < 9; i ++)
        {
            int unitIndex = (x / 3) * 3 + (y / 3);
            
            bool& row = rows[x][i];
            bool& col = cols[y][i];
            bool& unit = units[unitIndex][i];
            
            if(!row && !col && !unit)
            {
                row = true;
                col = true;
                unit = true;
                ch = '1' + i;
                
                if(solveSudoku(board, x, y + 1, index + 1))
                {
                    return true;
                }
                
                ch = '.';
                row = false;
                col = false;
                unit = false;
            }
        }
        
        return false;
    }
};