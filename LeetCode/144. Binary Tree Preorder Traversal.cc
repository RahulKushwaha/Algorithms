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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> output;
        
        PreOrderTraversal(root, output);
        
        return output;
    }
    
    void PreOrderTraversal(TreeNode * root, vector<int>& output)
    {
        if(root == NULL)
        {
            return;
        }
        
        output.push_back(root->val);
        
        PreOrderTraversal(root->left, output);
        PreOrderTraversal(root->right, output);
    }
};