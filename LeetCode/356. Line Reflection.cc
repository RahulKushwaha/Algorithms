class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        int length = points.size();
        if(length == 0)
        {
            return true;
        }
        
        set<pair<int, int>> lookup;
        
        int minX = points[0].first;
        int maxX = minX;
        
        for(int i = 0; i < length; i ++)
        {
            pair<int, int>& point = points[i];
            minX = min(minX, point.first);
            maxX = max(maxX, point.first);
            
            lookup.insert(point);
        }
        
        
        for(int i = 0; i < length; i ++)
        {
            pair<int, int> point = points[i];
            point.first = maxX + minX - point.first;
            set<pair<int, int>>::iterator itr = lookup.find(point);
            if(itr == lookup.end())
            {
                return false;
            }
        }
        
        return true;
    }
};