class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        int length = tickets.size();
        vector<string> output;
        if(length == 0)
        {
            return output;
        }
        
        for(int i = 0; i < length; i ++)
        {
            graph[tickets[i].first].push(tickets[i].second);
        }
        
        list<string> path;
        dfs("JFK", path);
        
        for(list<string>::iterator itr = path.begin(); itr != path.end(); itr ++)
        {
            output.push_back(*itr);
        }
        
        return output;
    }
    
    void dfs(string city, list<string>& output)
    {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>>>::iterator itr = graph.find(city);
        if(itr != graph.end())
        {
            while(itr->second.empty() == false)
            {
                string nextCity = itr->second.top();
                itr->second.pop();
                dfs(nextCity, output);
            }
        }
        
        output.push_front(city);
    }
};