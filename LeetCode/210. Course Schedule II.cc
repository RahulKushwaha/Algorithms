enum Color {black, grey, white};

class Solution {
public:
    bool dfsIteration(unordered_map<int, vector<int>>& graph,
                      int startNode,
                      Color * visited,
                      vector<int>& output)
    {
        if(visited[startNode] == black || visited[startNode] == grey)
        {
            return false;
        }
        
        visited[startNode] = grey;
        vector<int>::iterator endMarker = graph[startNode].end();
        for(vector<int>::iterator itr = graph[startNode].begin(); itr != endMarker; itr ++)
        {
            if(visited[*itr] != black && dfsIteration(graph, *itr, visited, output) == false)
            {
                return false;
            }
        }
        
        visited[startNode] = black;
        output.insert(output.begin(), startNode);
        
        return true;
    }
    
    void dfs(unordered_map<int, vector<int>>& graph, int n, vector<int>& output)
    {
        Color visited[n];
        
        for(int i = 0; i < n; i ++)
        {
            visited[i] = white;
        }
        
        for(int i = 0; i < n; i ++)
        {
            if(visited[i] == white)
            {
                if(dfsIteration(graph, i, visited, output) == false)
                {
                    output.clear();
                    return;
                }
            }
        }
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> output;
        int length = prerequisites.size();

        unordered_map<int, vector<int>> graph;
        
        for(int i = 0; i < numCourses; i ++)
        {
            vector<int> forwardEdges; 
            graph.insert(pair<int, vector<int>>(i, forwardEdges));
        }
        
        for(int i = 0; i < length; i ++)
        {
            pair<int, int> edge = prerequisites[i];
            graph[edge.second].push_back(edge.first);
        }
        
        dfs(graph, numCourses, output);
        
        return output;
    }
};