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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> output; 
        if(n == 0)
        {
            return output;
        }
        
        return getTree(1, n);
    }
    
    TreeNode* getNewNode(int val)
    {
        TreeNode* node = new TreeNode(val);
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    
    vector<TreeNode*> getTree(int l, int h)
    {
        vector<TreeNode*> nodes;
        if(l > h)
        {
            return nodes;
        }
        
        if(l == h)
        {
            TreeNode * node = getNewNode(l);
            nodes.push_back(node);
            return nodes;
        }
        
        for(int i = l; i <= h ; i ++)
        {
            vector<TreeNode*> leftNodes = getTree(l, i - 1);
            vector<TreeNode*> rightNodes= getTree(i + 1, h);
            if(leftNodes.size() == 0)
            {
                for(int j = 0; j < rightNodes.size(); j ++)
                {
                    TreeNode* node = getNewNode(i);
                    node->right = rightNodes[j];
                    node->left = NULL;
                    nodes.push_back(node);
                }
            }
            else if(rightNodes.size() == 0)
            {
                for(int j = 0; j < leftNodes.size(); j ++)
                {
                    TreeNode* node = getNewNode(i);
                    node->left = leftNodes[j];
                    node->right = NULL;
                    nodes.push_back(node);
                }
            }
            else
            {
                for(int a = 0; a < leftNodes.size(); a ++)
                {
                    for(int b = 0; b < rightNodes.size(); b ++)
                    {
                        TreeNode* node = getNewNode(i);
                        node->left = leftNodes[a];
                        node->right = rightNodes[b];
                        nodes.push_back(node);
                    }
                }
            }
        }
        
        return nodes;
    }
};