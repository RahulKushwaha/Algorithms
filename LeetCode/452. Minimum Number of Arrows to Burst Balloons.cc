class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int length = points.size();
        if(length == 0){
            return 0;
        }
        
        sort(points.begin(), points.end());
        
        int arrows = 0;
        int k = 0;
        
        for(int i = 0; i < length; i ++)
        {
            pair<int, int>& currentBalloon = points[i];
            
            for(int j = k; j < i; j ++){
                if(points[j].second < currentBalloon.first)
                {
                    arrows ++;
                    k = i;
                    break;
                }
            }
        }
        
        return arrows + 1;
    }
};