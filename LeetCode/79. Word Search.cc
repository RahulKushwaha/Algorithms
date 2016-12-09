vector<pair<int, int>> directionOffsets {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        if(rowSize == 0)
        {
            return false;
        }
        
        int colSize = board[rowSize - 1].size();
        
        if(word.size() == 0)
        {
            return 0;
        }
        
        if(rowSize == 1 && colSize == 1 && word.size() == 1)
        {
            return board[0][0] == word[0];
        }
        
        vector<vector<bool>> visited;
        for(int i = 0; i < rowSize; i ++)
        {
            vector<bool> row;
            row.resize(colSize);
            visited.push_back(row);
            for(int j = 0; j < colSize; j ++)
            {
                visited[i][j] = false;
            }
        }
        
        
        for(int i = 0; i < rowSize; i ++)
        {
            for(int j = 0; j < colSize; j ++)
            {
                if(exist(board, visited, word, 0, i, j, rowSize, colSize))
                {
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool exist(vector<vector<char>>& board,
               vector<vector<bool>>& visited,
               string word,
               int index,
               int i,
               int j,
               int rowSize,
               int colSize)
    {
        if(index == word.size())
        {
            return true;
        }
        
        bool result = false;
        
        for(int x = 0; x < 4; x ++)
        {
            pair<int, int> offset = directionOffsets[x];
            int a = i + offset.first;
            int b = j + offset.second;
            
            if(a < rowSize && b < colSize && a >= 0 && b >= 0)
            {
                if(visited[a][b] == false && board[a][b] == word[index])
                {
                    visited[a][b] = true;
                    if(exist(board, visited, word, index + 1, a, b, rowSize, colSize))
                    {
                        return true;
                    }
                    
                    visited[a][b] = false;
                }
            }
        }
        
        return false;
    }
};