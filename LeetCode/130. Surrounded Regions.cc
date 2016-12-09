class Solution {
public:

    bool bfs(vector<vector<char>>& board, int i, int j, int rows, int cols, bool setVal, char val)
    {
        queue<pair<int, int>> nodes;
        nodes.push(make_pair(i, j));
        visited[i][j] = true;
        bool flag = false;
        
        while(nodes.empty() == false)
        {
            pair<int, int>& top = nodes.front();
            int x = top.first; 
            int y = top.second;

            if(x + 1 < rows)
            {    
                if(board[x + 1][y] == 'O')
                {
                    if(visited[x + 1][y] == false)
                    {
                        visited[x + 1][y] = true;
                        nodes.push(make_pair(x + 1, y));
                    }
                }
            }
            
            if(y + 1 < cols)
            {
                if(board[x][y + 1] == 'O')
                {
                    if(visited[x][y + 1] == false)
                    {
                        visited[x][y + 1] = true;
                        nodes.push(make_pair(x, y + 1));
                    }
                }
            }
            
            if(x - 1 >= 0)
            {
                if(board[x - 1][y] == 'O')
                {
                    if(visited[x - 1][y] == false)
                    {
                        visited[x - 1][y] = true;
                        nodes.push(make_pair(x - 1, y));
                    }
                }
            }
            
            if(y - 1 >= 0)
            {
                if(board[x][y - 1] == 'O')
                {
                    if(visited[x][y - 1] == false)
                    {
                        visited[x][y - 1] = true;
                        nodes.push(make_pair(x, y - 1));
                    }
                }
            }
            
            board[x][y] = val;
            nodes.pop();
        }
        
        return true;
    }
    
    bool visited [500][500];

    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows == 0)
        {
            return;
        }
        
        int cols = board[rows - 1].size();
        
        if(cols == 0)
        {
            return;
        }
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                visited[i][j] = false;
            }
        }

        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if((i == 0 || j == 0 || i == rows - 1 || j == cols - 1) && board[i][j] == 'O')
                {
                    bfs(board, i, j, rows, cols, false, 'S');
                }
            }
        }
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                char &ch = board[i][j];
                if(ch == 'O')
                {
                    ch = 'X';
                }
                else if(ch == 'S')
                {
                    ch = 'O';
                }
            }
        }
    }
};