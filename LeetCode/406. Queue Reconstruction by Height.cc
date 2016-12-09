bool compare(pair<int, int>& x, pair<int, int>& y)
{
    if(x.first == y.first)
    {
        return x.second < y.second;    
    }
    
    return x.first > y.first;    
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int length = people.size();
        sort(people.begin(), people.end(), compare);
        vector<pair<int, int>> output;
        
        for(int i = 0; i < length; i ++)
        {
            output.insert(output.begin() + people[i].second, people[i]);
        }
        
        return output;
    }
};