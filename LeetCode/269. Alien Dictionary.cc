enum Color {white, grey, black};

class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& graph, int startNode, unordered_map<int, Color>& visited, string& output)
    {
        visited[startNode] = grey;
        
        unordered_map<int, vector<int>>::iterator itr = graph.find(startNode);
        
        if(itr != graph.end())
        {
            vector<int>::iterator endMarker = itr->second.end();
            for(vector<int>::iterator neighbor = itr->second.begin(); neighbor != endMarker; neighbor ++)
            {
                //cout<<(char)(startNode + 'a')<<" "<<(char)(*neighbor + 'a')<<" "<<visited[*neighbor]<<endl;
                if(visited[*neighbor] == white)
                {
                    if(dfs(graph, *neighbor, visited, output) == false)
                    {
                        return false;
                    }
                }
                else if(visited[*neighbor] == grey)
                {
                    //cout<<"edge Detected";
                    return false;
                }
            }
        }
        
        visited[startNode] = black;
        
        output.insert(output.begin(), ('a' + startNode));
        return true;
    }
    
    void topologicalSort(unordered_map<int, vector<int>>& graph, string& output, unordered_map<int, Color>& visited)
    {
        unordered_map<int, vector<int>>::iterator graphEnd = graph.end();
        
        for(unordered_map<int, vector<int>>::iterator itr = graph.begin(); itr != graphEnd; itr ++)
        {
            if(visited[itr->first] == white)
            {
                if(dfs(graph, itr->first, visited, output) == false)
                {
                    //cout<<"Edge Detected"<<endl;
                    output.clear();
                    return;
                }
            }
        }
    }

    string alienOrder(vector<string>& words) {
        int length = words.size();
        string output;
        
        if(length == 0)
        {
            return output;
        }
        
        unordered_map<int, vector<int>> graph;
        for(int i = 1; i < length; i ++)
        {
            string& lastWord = words[i - 1];
            string& word = words[i];
            
            int limit = min(lastWord.size(), word.size());
            for(int j = 0; j < limit; j ++)
            {
                int lastCh = lastWord[j] - 'a';
                int ch = word[j] - 'a';
                if(lastCh != ch)
                {
                    graph[lastCh].push_back(ch);
                    
                    break;
                }
            }
        }
        
        unordered_map<int, Color> visited;
        for(int i = 0; i < length; i ++)
        {
            string &word = words[i];
            int wordLenth = word.size();
            for(int j = 0; j < wordLenth; j ++)
            {
                int node = word[j] - 'a';
                visited[node] = white;
                graph[node];
            }
        }
        
        topologicalSort(graph, output, visited);
        
        return output;
    }
};