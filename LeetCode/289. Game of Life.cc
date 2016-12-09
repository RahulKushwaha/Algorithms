class Solution {
public:
    int getNeighbors(vector<vector<int>>& board, int i, int j, int rows, int cols)
    {
        int counter = 0;
        if(i + 1 < rows)
        {
            if(board[i + 1][j])
            {
                counter ++;
            }
            
            if(j + 1 < cols)
            {
                if(board[i + 1][j + 1])
                {
                    counter ++;
                }
            }
            
            if(j - 1 >= 0)
            {
                if(board[i + 1][j - 1])
                {
                    counter ++;
                }
            }
        }
        
        if(i - 1 >= 0)
        {
            if(board[i - 1][j])
            {
                counter ++;
            }
            
            if(j + 1 < cols)
            {
                if(board[i - 1][j + 1])
                {
                    counter ++;
                }
            }
            
            if(j - 1 >= 0)
            {
                if(board[i - 1][j - 1])
                {
                    counter++;
                }
            }
        }
        
        if(j - 1 >= 0)
        {
            if(board[i][j - 1])
            {
                counter ++;
            }
        }
        
        if(j + 1 < cols)
        {
            if(board[i][j + 1])
            {
                counter ++;
            }
        }
        
        return counter;
    }
    
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        
        if(rows == 0)
        {
            return;
        }
        
        int cols = board[rows - 1].size();
        
         vector<pair<int, int>> changed;
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                int neighbors = getNeighbors(board, i, j, rows, cols);
                if(board[i][j])
                {
                    if(neighbors < 2 || neighbors > 3)
                    {
                        changed.push_back(make_pair(i, j));
                    }
                }
                else
                {
                    if(neighbors == 3)
                    {
                        changed.push_back(make_pair(i, j));
                    }
                }
            }
        }
        
        vector<pair<int, int>>::iterator endMarker = changed.end();
        for(vector<pair<int, int>>::iterator itr = changed.begin(); itr !=  endMarker; itr ++)
        {
            int i = itr->first;
            int j = itr->second;
            if(board[i][j])
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = 1;
            }
        }
    }
};