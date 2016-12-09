class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int x = matrix.size();
        
        if(x == 0)
        {
            return 0;
        }
        
        int y = matrix[x - 1].size();
        
        bool ** visited = new bool*[x];
    
        for(int i = 0; i < x; i ++)
        {
            visited[i] = new bool[y];
            for(int j = 0; j < y; j ++)
            {
                visited[i][j] = false;
            }
        }
        
        int ** lookup = new int*[x];
    
        for(int i = 0; i < x; i ++)
        {
            lookup[i] = new int[y];
            for(int j = 0; j < y; j ++)
            {
                lookup[i][j] = -1;
            }
        }
        
        int longest = INT_MIN;
        for(int i = 0; i < x; i ++ )
        {
            for(int j = 0; j < y; j ++)
            {
                int current = longestIncreasingPath(matrix, visited, lookup, i, j, x, y);
                if(current > longest)
                {
                    longest = current;
                }
            }
        }

        return longest == INT_MIN? 0 : longest;
    }
    
    int longestIncreasingPath(vector<vector<int>> &matrix,
                               bool** visited,
                               int ** lookup,
                               int i, 
                               int j,
                               int x, 
                               int y)
    {
        if(i < 0 || j < 0 || i >= x || j >= y )
        {
            return 0;
        }
        
        if(lookup[i][j] != -1)
        {
            return lookup[i][j];
        }
        
        int currentPath = 0;
        int west = 0;
        int east = 0; 
        int north = 0; 
        int south = 0;
        
        int element = matrix[i][j];
        
        if(i + 1 < x)
        {
            bool &flag = (visited[i + 1][j]);
            if(flag == false && element > matrix[i + 1][j])
            {
                flag == true;
                south = longestIncreasingPath(matrix, visited, lookup, i + 1, j , x, y);
                if(south > currentPath)
                {
                    currentPath = south;    
                }
                
                flag == false;
            }
        }
        
        if(i - 1 >= 0)
        {
            bool& flag = visited[i - 1][j];
            if(flag == false && element > matrix[i - 1][j])
            {
                flag == true;
                north = longestIncreasingPath(matrix, visited, lookup, i - 1, j , x, y);
                if(north > currentPath)
                {
                    currentPath = north;
                }
                
                flag == false;
            }
        }
        
        if(j + 1 < y)
        {
            bool& flag = visited[i][j + 1];
            if(flag == false && element > matrix[i][j + 1])
            {
                flag == true;
                east = longestIncreasingPath(matrix, visited, lookup, i, j + 1 , x, y);
                if(east > currentPath)
                {
                    currentPath = east;
                }
                
                flag == false;
            }
        }
        
        if(j - 1 >= 0)
        {
            bool &flag = visited[i][j - 1]; 
            if(flag == false && element > matrix[i][j - 1])
            {
                flag == true;
                west = longestIncreasingPath(matrix, visited, lookup, i, j - 1, x, y);
                if(west > currentPath)
                {
                    currentPath = west;
                }
                
                flag == false;
            }
        }
        
        lookup[i][j] = currentPath + 1;
        
        return currentPath + 1;
    }
};