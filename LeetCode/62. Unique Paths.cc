class Solution {
public:
    int uniquePaths(int m, int n) {
        int * paths = new int[n];
        
        for(int i = 0; i < n; i ++)
        {
            paths[i] = 1;
        }
        
        for(int i = 0; i < m  - 1; i ++)
        {
            paths[0] = 1;
            for(int j = 1; j < n; j ++)
            {
                paths[j] = paths[j - 1] + paths[j]; 
            }
        }
        
        return paths[n - 1];
    }
};