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
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        sumOfLeftLeaves(root, ans, false);
        
        return ans;
    }
    
    void sumOfLeftLeaves(TreeNode* root, int& sum, bool left)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->right == NULL && left)
        {
            sum += root->val;
        }
        
        sumOfLeftLeaves(root->left, sum, true);
        sumOfLeftLeaves(root->right, sum, false);
    }
};