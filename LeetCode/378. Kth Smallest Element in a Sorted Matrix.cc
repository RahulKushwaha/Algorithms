class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        if(n == 0)
        {
            return -1;
        }
        
        int l = matrix[0][0], u = matrix[n - 1][n - 1];
        
        int mid = 0;
        while(l < u)
        {
            mid = ((u - l) / 2) + l;
            
            int position = 0;
            for(int i = 0; i < n; i ++)
            {
                position += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
            }
            
            if(position < k)
            {
                l = mid + 1;
            }
            else
            {
                u = mid;
            }
        }
        
        return l;
    }
};