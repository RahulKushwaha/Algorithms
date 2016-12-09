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

    void dfs(TreeNode* root, TreeNode* node, vector<TreeNode*>& nodes, bool& flag)
    {
        if(root && flag)
        {
            if(root == node)
            {
                flag = false;
                return;
            }
            
            if(flag && root->left)
            {
                nodes.push_back(root->left);
                dfs(root->left, node, nodes, flag);
            }
            
            if(flag && root->right)
            {
                nodes.push_back(root->right);
                dfs(root->right, node, nodes, flag);
            }
            
            if(flag == false)
            {
                return ;
            }
            
            nodes.pop_back();
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
        {
            return NULL;
        }
        
        vector<TreeNode*> nodesP;
        bool flag = true;
        nodesP.push_back(root);
        dfs(root, p, nodesP, flag);
        
        vector<TreeNode*> nodesQ;
        flag = true;
        nodesQ.push_back(root);
        dfs(root, q, nodesQ, flag);
        
        TreeNode* parent = NULL;
        int i = 0;
        while(i < nodesQ.size() && i < nodesP.size())
        {
            TreeNode* topP = nodesP[i];
            TreeNode* topQ = nodesQ[i];
            
            if(topP != topQ)
            {
                break;
            }
            
            if(topP == p)
            {
                parent = p;
                break;
            }
            
            if(topQ == q)
            {
                parent = q;
                break;
            }
            
            parent = topP;
            
            i++;
        }
        
        return parent;
    }
};