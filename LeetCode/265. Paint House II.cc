class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int length = costs.size();
        
        if(length == 0)
        {
            return 0;
        }
        
        int k = costs[0].size();
        for(int i = 1; i < length; i ++)
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            for(int j = 0; j < k; j ++)
            {
                pq.push(pair<int, int>(costs[i - 1][j], j));
            }
            
            pair<int, int> top = pq.top();
            
            for(int j = 0; j < k; j ++)
            {
                if(top.second == j)
                {
                    pq.pop();
                    pair<int, int> secondTop = pq.top();
                    costs[i][j] += secondTop.first;
                }
                else
                {
                    costs[i][j] += top.first;
                }
            }
        }
        
        int cost = INT_MAX;
        for(int j = 0; j < k; j ++)
        {
            cost = min(cost, costs[length - 1][j]);
        }
        
        return cost;
    }
};