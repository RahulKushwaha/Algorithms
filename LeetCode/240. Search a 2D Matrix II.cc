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
       int current;
       while(i >= 0 && j < cols)
       {
            current = matrix[i][j];
           if(target == current)
           {
               return true;
           }
           
           if(target > current)
           {
               j ++;
               continue;
           }
           
           if(target < current)
           { 
               i --;
           }
       }
       
       return false;
    }
};