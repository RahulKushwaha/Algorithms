class Solution {
public:
    unordered_map<int, int> lookup;
    int numTrees(int n) {
        if(n == 1)
        {
            return 1;
        }
        
        return numTrees(1, n);
    }
    
    int numTrees(int l, int h)
    {
        if(l >= h)
        {
            return 1;
        }
        
        unordered_map<int, int>::iterator itr = lookup.find(h - l + 1);
        if(itr != lookup.end())
        {
            return itr->second;
        }
        
        int total = 0;
        for(int i = l; i <= h; i ++)
        {
            int left = numTrees(l, i - 1); 
            int right = numTrees(i + 1, h);
            total += (left * right);
        }
        
        lookup[h - l + 1] = total;
        
        return total;
    }
};