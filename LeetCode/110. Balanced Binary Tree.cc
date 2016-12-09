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
    int getHeight(TreeNode * root, bool& balanced)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = getHeight(root->left, balanced) + 1;
        int right = getHeight(root->right, balanced) + 1;
        
        balanced &= abs(left - right) > 1 ? false : true;
        
        return left > right? left: right;
    }
    
    bool isBalanced(TreeNode* root) {
        bool output = true;
        getHeight(root, output);
        
        return output;
    }
};