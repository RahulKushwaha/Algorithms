class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        int output = 0;
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(i - 1 >= 0)
                {
                    if(board[i - 1][j] == 'X')
                    {
                        continue;
                    }
                }
                
                if(j - 1 >= 0)
                {
                    if(board[i][j - 1] == 'X')
                    {
                        continue;
                    }
                }
                
                if(board[i][j] == 'X')
                {
                    output ++;
                }
            }
        }
        
        return output;
    }
};