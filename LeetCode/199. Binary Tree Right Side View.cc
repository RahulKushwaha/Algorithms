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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        
        if(root == NULL)
        {
            return output;
        }
        
        int maxDepth = 0;
        rightSideView(root, maxDepth, 1, output);
        
        return output;
    }
    
    void rightSideView(TreeNode* root, int& maxDepth, int depth, vector<int>& output)
    {
        if(maxDepth < depth)
        {
            output.push_back(root->val);
            maxDepth = depth;
        }
        
        if(root->right != NULL)
            rightSideView(root->right, maxDepth, depth + 1, output);
        
        if(root->left != NULL)
            rightSideView(root->left, maxDepth, depth + 1, output);
    }
};