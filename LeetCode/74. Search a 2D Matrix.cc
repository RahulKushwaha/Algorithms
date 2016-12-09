class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       
       int rows = matrix.size();
       if(rows == 0)
       {
           return false;
       }
       
       int cols = matrix[rows - 1].size();
       
       int i = rows - 1;
       int j = 0;
       
       while(i >= 0 && j < cols)
       {
           if(target == matrix[i][j])
           {
               return true;
           }
           
           if(target > matrix[i][j])
           {
               j ++;
               continue;
           }
           
           if(target < matrix[i][j])
           { 
               i --;
           }
       }
       
       return false;
    }
};