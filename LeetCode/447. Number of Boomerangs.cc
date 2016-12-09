class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int length = points.size();
        int output = 0;
        
        for(int i = 0; i < length; i ++)
        {
            unordered_map<int, int> lookup;
            pair<int, int>& x = points[i];
            
            for(int j = 0; j < length; j ++)
            {
                if(i == j)
                {
                    continue;
                }
                
                pair<int, int>& y = points[j];
                
                int distance = (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second);
                lookup[distance] ++;
            }
            
            for(unordered_map<int, int>::iterator itr = lookup.begin(); itr != lookup.end(); itr ++)
            {
                output += itr->second * (itr->second - 1);
            }
            
            lookup.clear();
        }
        
        return output;
    }
};