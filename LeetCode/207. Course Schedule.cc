enum Color {white, grey, black};

class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, Color * visited, int startNode)
    {
        if(visited[startNode] == black || visited[startNode] == grey)
        {
            return false;
        }
        
        visited[startNode] = grey;
        vector<int>::iterator endMarker = graph[startNode].end();
        for(vector<int>::iterator itr = graph[startNode].begin(); itr != endMarker; itr ++)
        {
            if(visited[*itr] != black && dfs(graph, visited, *itr) == false)
            {
                return false;
            }
        }
        
        visited[startNode] = black;
        
        return true;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        
        for(int i = 0; i < numCourses; i ++)
        {
            vector<int> forwardEdges;
            graph.insert(pair<int, vector<int>>(i, forwardEdges));
        }
        
        for(int i = 0; i < prerequisites.size(); i ++)
        {
            pair<int, int> edge = prerequisites[i];
            graph[edge.second].push_back(edge.first);
        }
        
        Color visited[numCourses];
        
        for(int i = 0; i < numCourses; i ++)
        {
            visited[i] = white;
        }
        
        for(int i = 0; i < numCourses; i ++)
        {
            if(visited[i] == white && dfs(graph, visited, i) == false)
            {
                return false;
            }
        }
        
        return true;
    }
};