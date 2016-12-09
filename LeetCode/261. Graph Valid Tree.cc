class Solution {
public:
    int * links; 
    int * ranks;
    
    int find(int node)
    {
        int parent = -1;
        if(links[node] != -1)
        {
            parent = find(links[node]);
            links[node] = parent;
        }
        else
        {
            parent = node;
        }
        
        return parent; 
    }
    
    bool unionSet(int a, int b)
    {
        int p1 = find(a);
        int p2 = find(b);
        
        if(p1 == p2)
        {
            return false;
        }
        
        int p, c;
        
        if(ranks[p1] < ranks[p2])
        {
            p = p1;
            c = p2;
        }
        else
        {
            p = p2;
            c = p1;
        }
        
        links[c] = p;
        ranks[p] += ranks[c];
        
        return true;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if(n == 0)
        {
            return true;
        }
        
        links = new int[n];
        ranks = new int[n];
        
        for(int i = 0; i < n; i ++)
        {
            links[i] = -1;
            ranks[i] = 1;
        }
        
        int numberOfEdges = edges.size();
        
        for(int i = 0; i < numberOfEdges; i++)
        {
            pair<int, int> edge = edges[i];
            if(unionSet(edge.first, edge.second) == false)
            {
                return false;
            }
        }
        
        int rootCount = 0;
        for(int i = 0; i < n; i ++)
        {
            if(links[i] == -1)
            {
                rootCount ++;
            }
        }
        
        return rootCount == 1;
    }
};