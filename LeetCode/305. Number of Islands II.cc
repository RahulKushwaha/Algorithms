class Solution {
public:
    int *links;
    int *ranks;
    int ** grid;
    int rows, cols;
    
    int find(int a)
    {
        int parent = a;
        if(links[a] != a)
        {
            parent = find(links[a]);
            links[a] = parent;
        }
        
        return parent;
    }
    
    bool unionSet(int a, int b)
    {
        int p1 = find(a);
        int p2 = find(b);
        
        if(p1 == p2)
        {
            return false;
        }
        
        int p, c;
        
        if(ranks[p1] < ranks[p2])
        {
            p = p2;
            c = p1;
        }
        else
        {
            p = p1;
            c = p2;
        }
        
        links[c] = p;
        ranks[p] += ranks[c];
        
        return true;
    }
    
    vector<int> getNeighbor(int i, int j)
    {
        vector<int> neighbors;
        if(i + 1 < rows && grid[i + 1][j])
        {
            neighbors.push_back((i + 1) * cols + j);
        }
        
        if(i - 1 >= 0 && grid[i - 1][j])
        {
            neighbors.push_back((i - 1) * cols + j);
        }
        
        if(j + 1 < cols && grid[i][j + 1])
        {
            neighbors.push_back((i) * cols + j + 1);
        }
        
        if(j - 1 >= 0 && grid[i][j - 1])
        {
            neighbors.push_back((i) * cols + j - 1);
        }
        
        return neighbors;
    }
    
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> output;
        
        if(m == 0)
        {
            return output;
        }
        
        int cellCount = m * n;
        
        rows = m; 
        cols = n;
        
        links = new int[cellCount];
        ranks = new int[cellCount];
        
        for(int i = 0; i < cellCount; i ++)
        {
            links[i] = i;
            ranks[i] = 1;
        }
        
        grid = new int*[rows];
        for(int i = 0; i < rows; i ++)
        {
            grid[i] = new int[cols];
            
            for(int j = 0; j < cols; j ++)
            {
                grid[i][j] = 0;
            }
        }
        
        int positionsCount = positions.size();
        int numberOfIslands = 0;
        for(int i = 0; i < positionsCount; i ++)
        {
            pair<int, int> cell = positions[i];
            grid[cell.first][cell.second] = 1;
            vector<int> neighbors = getNeighbor(cell.first, cell.second);
            
            if(neighbors.size() != 0)
            {
                int current= cell.first * cols + cell.second;
                int counter = -1;
                for(int j = 0; j < neighbors.size(); j ++)
                {
                    if(unionSet(current, neighbors[j]))
                    {
                        counter ++;
                    }
                }
                
                if(counter != -1)
                {
                    numberOfIslands -= counter;
                }
            }
            else 
            {
                numberOfIslands ++;
            }
            
            output.push_back(numberOfIslands);
        }
        
        return output;
    }
};