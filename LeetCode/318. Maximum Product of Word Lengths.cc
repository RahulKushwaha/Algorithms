class Solution {
public:

    int maxProduct(vector<string>& words) {
        if(words.size() == 0)
        {
            return 0;
        }
        
        vector<int> mask;
        mask.resize(words.size());
        
        for(int i = 0; i < words.size(); i ++)
        {
            mask[i] = 0;
            int limit = words[i].size();
            for(int j = 0; j < limit; j ++)
            {
                mask[i] |= (1<< (words[i][j] - 'a'));
            }
        }
        
        int product = 0;
        
        for(int i = 0; i < words.size(); i ++)
        {
            for(int j = i + 1; j < words.size(); j++)
            {
                if(mask[i] & mask[j])
                {
                    continue;
                }
                else
                {
                    int currentProduct = words[i].size() * words[j].size();
                    if(currentProduct > product)
                    {
                        product = currentProduct;
                    }
                }
            }
        }
        
        return product;
    }
};