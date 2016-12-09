/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
typedef UndirectedGraphNode UGN;
class Solution {
public:
    map<UGN*, UGN*> lookup;
    set<UGN*> visited;
    
    bool isVisited(UGN* node)
    {
        return visited.find(node) != visited.end();
    }
    
    UGN* getNewNode(UGN* node)
    {
        map<UGN*, UGN*>::iterator itr = lookup.find(node);
        if(itr == lookup.end())
        {
            UGN* newNode = new UGN(node->label);
            lookup.insert(make_pair(node, newNode));
            
            itr = lookup.find(node);
        }
        
        return itr->second;
    }
    
    void dfs(UGN* startNode)
    {
        if(isVisited(startNode) == false)
        {
            UGN* newNode = getNewNode(startNode);
            visited.insert(startNode);
            
            for(int i = 0; i < startNode->neighbors.size(); i ++)
            {
                UGN* neighbor = getNewNode(startNode->neighbors[i]);
                newNode->neighbors.push_back(neighbor);
                dfs(startNode->neighbors[i]);
            }
        }
    }
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
        {
            return NULL;
        }
        
        dfs(node);
        
        return lookup.find(node)->second;
    }
};