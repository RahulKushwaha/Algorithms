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
    int closestValue(TreeNode* root, double target) {
        if(root == NULL)
        {
            return 0;
        }
        
        TreeNode* ans = root;
        while(root)
        {
            if(abs(root->val - target) < abs(ans->val - target))
            {
                ans = root;
            }
            
            if(root->val > target)
            {
                root = root->left;
            }
            else
            {
                root = root->right;
            }
        }
        
        return ans->val;
    }
};