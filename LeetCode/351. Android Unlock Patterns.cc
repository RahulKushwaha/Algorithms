class Solution {
public:
    int numberOfPatterns(int m, int n) {
        if(n == 0)
        {
            return 0;
        }
        
        bool visited[10] = {0};
        int ** skip = new int*[10];
        for(int i = 0; i <= 9; i ++)
        {
            skip[i] = new int[10];
            for(int j = 0; j <= 9; j ++)
            {
                skip[i][j] = 0;
            }
        }
        
        skip[1][3] = skip[3][1] = 2;
        skip[7][9] = skip[9][7] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        
        skip[1][9] = skip[9][1] = skip[3][7] = skip[7][3] = skip[2][8] = skip[8][2] = skip[6][4] = skip[4][6] = 5; 
         
        int output = 0;
        for(int i = 1; i <= 9; i ++)
        {
            visited[i] = true;
            combinations(i, (bool*)visited, skip, m, n, 1, output);
            visited[i] = false;
        }
        
        return output;
    }
    
    void combinations(int current, bool* visited, int** skip, int m, int n, int currentLength, int& output)
    {
        if(currentLength >= m && currentLength <= n)
        {
            output++;
        }
        
        if(currentLength >= n)
        {
            return;
        }
        
        for(int i = 1; i <= 9; i ++)
        {
            if(visited[i] == false && (visited[skip[current][i]] || skip[current][i] == 0))
            {
                visited[i] = true;
                combinations(i, visited, skip, m, n, currentLength + 1, output);
                visited[i] = false;
            }
        }
    }
};