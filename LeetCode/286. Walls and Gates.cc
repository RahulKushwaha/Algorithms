class Solution {
public:

    void bfs(queue<pair<int, int>>& q, vector<vector<int>>& rooms, bool ** visited, int rows, int cols)
    {
        while(q.empty() == false)
        {
            pair<int, int> top = q.front();
            int i = top.first;
            int j = top.second;
            q.pop();
            int current = rooms[i][j];
            
            if(i + 1 < rows && visited[i + 1][j] == false && rooms[i + 1][j] == INT_MAX)
            {
                q.push(make_pair(i + 1, j));
                
                rooms[i + 1][j] = min(rooms[i + 1][j], current + 1);
                visited[i + 1][j] = true;
            }
        
            if(j + 1 < cols && visited[i][j + 1] == false && rooms[i][j + 1] == INT_MAX)
            {
                q.push(make_pair(i, j + 1));
                
                rooms[i][j + 1] = min(rooms[i][j + 1], current + 1);
                visited[i][j + 1] = true;
            }
            
            if(i - 1 >= 0 && visited[i - 1][j] == false && rooms[i - 1][j] == INT_MAX)
            {
                q.push(make_pair(i - 1, j));
                
                rooms[i - 1][j] = min(rooms[i - 1][j], current + 1);
                visited[i - 1][j] = true;
            }
            
            if(j - 1 >= 0 && visited[i][j - 1] == false && rooms[i][j - 1] == INT_MAX)
            {
                q.push(make_pair(i, j - 1));
                
                rooms[i][j - 1] = min(rooms[i][j - 1], current + 1);
                visited[i][j - 1] = true;
            }
        }
    }

    void wallsAndGates(vector<vector<int>>& rooms) {
        int rows = rooms.size();
        if(rows == 0)
        {
            return;
        }
        
        int cols = rooms[rows - 1].size();

        bool ** visited = new bool*[rows];
        for(int i = 0; i < rows; i ++)
        {
            visited[i] = new bool[cols];
            for(int j = 0; j < cols; j ++)
            {
                visited[i][j] = false;
            }
        }
        
        queue<pair<int, int>> q;
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                if(rooms[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                }
            }
        }
        
        bfs(q, rooms, visited, rows, cols);
    }
};