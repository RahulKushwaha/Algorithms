class Solution {
public:
    int *links;
    int *ranks;
    
    int find(int element)
    {
        int parent = element;
        
        if(links[element] != element)
        {
            parent = find(links[element]);
            links[element] = parent;
        }
        
        return parent;
    }
    
    int unionSet(int a, int b)
    {
        int p1 = find(a);
        int p2 = find(b);
        
        if(p1 == p2)
        {
            return p1;
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
        
        return p;
    }
    
    int countComponents(int n, vector<pair<int, int>>& edges) {
        int length = n;
        if(length == 0)
        {
            return 0;
        }
        
        links = new int[length];
        ranks = new int[length];
        
        for(int i = 0; i < length; i ++)
        {
            ranks[i] = 1;
            links[i] = i;
        }
        
        int numberOfEdges = edges.size();
        
        for(int i = 0; i < numberOfEdges; i ++)
        {
            pair<int, int> edge = edges[i];
            unionSet(edge.first, edge.second);
        }
        
        int components = 0;
        for(int i = 0; i < length; i ++)
        {
            if(links[i] == i)
            {
                components ++;
            }
        }
        
        return components;
    }
};