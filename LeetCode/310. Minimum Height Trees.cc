class Solution {
public:
    int BFS(unordered_map<int, vector<int> >& graph, int * nodes, int n, int startNode, int & outputLength)
    {
        queue<int> q1;
        queue<int> q2;

        bool * visited = new bool[n];
        for(int i = 0; i < n; i ++)
        {
            nodes[i] = -1;
            visited[i] = false;
        }

        queue<int>* currentQueue = &q1;
        queue<int>* nextQueue = &q2;

        outputLength = 0;

        currentQueue->push(startNode);
        visited[startNode] = true;

        int lastNode = startNode;

        while(currentQueue->empty() == false)
        {
            int node = currentQueue->front();
            lastNode = node;
            unordered_map<int, vector<int> >::iterator itr = graph.find(node);
            if(itr != graph.end())
            {
                for(int i = 0; i < itr->second.size(); i++)
                {
                    if(visited[itr->second[i]] == false)
                    {
                        nextQueue->push(itr->second[i]);
                        visited[itr->second[i]] = true;
                        nodes[itr->second[i]] = node;
                    }
                }
            }

            currentQueue->pop();

            if(currentQueue->empty())
            {
                outputLength ++;
                if(currentQueue == &q1)
                {
                    currentQueue = &q2;
                    nextQueue = &q1;
                }
                else
                {
                    nextQueue = &q2;
                    currentQueue = &q1;
                }
            }
        }

        delete [] visited;
        return lastNode;
    }

    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<int> output;
        if(n == 0)
        {
            return output;
        }

        int * nodes = new int[n];

        unordered_map<int, vector<int> > graph;
        for(int i = 0; i < n - 1; i ++)
        {
            pair<int, int> edge = edges[i];
            nodes[edge.second] = edge.first;
            
            graph[edge.first].push_back(edge.second);
            graph[edge.second].push_back(edge.first);
        }

        int startNode = 0;
        int lastNode;
        int length;

        lastNode = BFS(graph, nodes, n, startNode, length);
        lastNode = BFS(graph, nodes, n, lastNode, length);
        
        bool odd = length % 2;
        length = length / 2;
        int counter = 0;
        int prev = lastNode;
        
        while(lastNode != -1)
        {
            if(counter == length)
            {
                output.push_back(lastNode);
                if(odd == 0)
                {
                    output.insert(output.begin(), prev);
                }
                break;
            }
            
            counter ++;
            prev = lastNode;
            lastNode = nodes[lastNode];
        }

        delete [] nodes;

        return output;
    }
};