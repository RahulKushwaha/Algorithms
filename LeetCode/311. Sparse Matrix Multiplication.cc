class Solution {
public:
    int product(vector<int>& a, vector<int>& b)
    {
        int total = 0;
        for(int i = 0; i < a.size(); i ++)
        {
            total += a[i] * b[i];
        }
        
        return total;
    }
    
    unordered_map<int, vector<int>> rowLookup;
    unordered_set<int> zeroRow;
    unordered_set<int> zeroCol;
    unordered_map<int, vector<int>> colLookup;
    
    vector<int>& getRow(vector<vector<int>>& A, int a, int aCols)
    {
        unordered_map<int, vector<int>>::iterator itr = rowLookup.find(a);
        if(itr == rowLookup.end())
        {
            vector<int> rowVector;
            bool zero = true;
            for(int l = 0; l < aCols; l ++)
            {
                rowVector.push_back(A[a][l]);
                
                if(A[a][l])
                {
                    zero = false;
                }
            }
            
            if(zero)
            {
                zeroRow.insert(a);
            }
            
            rowLookup.insert(make_pair(a, rowVector));
            
            itr = rowLookup.find(a);
        }
        
        return itr->second;
    }
    
    vector<int>& getCol(vector<vector<int>>& B, int a, int bRows)
    {
        unordered_map<int, vector<int>>::iterator itr = colLookup.find(a);
        if(itr == colLookup.end())
        {
            vector<int> colVector; 
            bool zero = true;
            for(int l = 0; l < bRows; l ++)
            {
                colVector.push_back(B[l][a]);
                
                if(B[l][a])
                {
                    zero = false;
                }
            }
            
            if(zero)
            {
                zeroCol.insert(a);
            }
            
            colLookup.insert(make_pair(a, colVector));
            
            itr = colLookup.find(a);
        }
        
        return itr->second;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int aRows = A.size();
        int bRows = B.size();
        
        int aCols = A[aRows - 1].size();
        int bCols = B[bRows - 1].size();
        
        vector<vector<int>> output;
        for(int i = 0; i < aRows; i ++)
        {
            vector<int> outputCol;
            outputCol.resize(bCols);
            output.push_back(outputCol);
            
            vector<int>& rowVector = getRow(A, i, aCols);
            
            for(int j = 0; j < bCols; j ++)
            {
                if(zeroRow.find(i) != zeroRow.end() || zeroCol.find(j) != zeroCol.end())
                {
                    output[i][j] = 0;
                }
                else
                {
                    vector<int>& colVector = getCol(B, j, bRows);
                    output[i][j] = product(rowVector, colVector);
                }
            }
        }
        
        return output;
    }
};