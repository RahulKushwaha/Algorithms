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
    int sumNumbers(TreeNode* root) {
        if(root == NULL)
        {
            return 0;
        }
        
        int output = 0;
        
        totalSum(root, output, 0);
        
        return output;
    }
    
    void totalSum(TreeNode * root, int& total, int currentTotal)
    {
        if(root == NULL)
        {
            return;
        }
        
        currentTotal *= 10;
        currentTotal += (root->val);
        
        if(root->left == NULL && root->right == NULL)
        {
            total += currentTotal;
        }

        totalSum(root->left, total, currentTotal);
        totalSum(root->right, total, currentTotal);
    }
};