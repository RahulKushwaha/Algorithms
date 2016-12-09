class Solution {
public:
    void nextCoordinates(int& i, int& j, int n)
    {
        int temp = i;
        i = j;
        j = n - temp;
    }
    
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 0)
        {
            return;
        }
        
        int size = n - 1;
        for(int i = 0; i < n / 2; i ++)
        {
            for(int j = i; j < n - i - 1 ;j ++)
            {
                int counter = 4;
                int a = i;
                int b = j;
                int last = matrix[i][j];
                while(counter > 0)
                {
                    nextCoordinates(a, b, size);
                    int temp = matrix[a][b];
                    matrix[a][b] = last;
                    last = temp;
                    counter --;
                }
            }
        }
    }
};