int min(int a, int b)
{
    if(a < b)
    {
        return a;
    }
    
    return b;
}

class Solution {
public:
    int minDistance(string word1, string word2) {
        int word1Size = word1.size();
        int word2Size = word2.size();
        if(word1Size == 0 && word2Size == 0)
        {
            return 0;
        }
        
        vector<vector<int>> lookup(word2Size + 1, vector<int> (word1Size + 1));
        
        for(int i = 0; i <= word2Size; i ++)
        {
            lookup[i][0] = i;
        }
        
        for(int j = 0; j <= word1Size; j ++)
        {
            lookup[0][j] = j;
        }
        
        for(int i = 0; i < word2Size; i ++)
        {
            for(int j = 0; j < word1Size; j ++)
            {
                int addCost = lookup[i][j + 1] + 1;
                int removeCost = lookup[i + 1][j] + 1;
                int substituteCost = lookup[i][j] + 1;
                if(word2[i] == word1[j])
                {
                    substituteCost --;
                }
                
                lookup[i + 1][j + 1] = min(addCost, min(removeCost, substituteCost));
            }
        }
        
        return lookup[word2Size][word1Size];
    }
};