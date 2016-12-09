/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> output;
        
        if(root == NULL)
        {
            return output;
        }
        
        generateVertical(root);
        
        for(map<int, vector<int>>::iterator itr = verticalOrders.begin(); itr != verticalOrders.end(); itr ++)
        {
            output.push_back(itr->second);
        }
        
        return output;
    }
    
    map<int, vector<int>> verticalOrders;
    
    void generateVertical(TreeNode* root)
    {
        int key = 0, depth = 0;
        queue<pair<int, TreeNode*>> current;
        current.push(make_pair(key, root));
        
        while(current.empty() == false)
        {
            pair<int, TreeNode*> top = current.front();
            verticalOrders[top.first].push_back(top.second->val);
            current.pop();
            
            if(top.second->left != NULL)
            {
                current.push(make_pair(top.first - 1, top.second->left));
            }
            
            if(top.second->right != NULL)
            {
                current.push(make_pair(top.first + 1, top.second->right));
            }
        }
    }
};