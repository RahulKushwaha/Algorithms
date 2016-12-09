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
    int countUnivalSubtrees(TreeNode* root) {
        int output = 0;
        countSubtrees(root, output);
        
        return output;
    }
    
    bool countSubtrees(TreeNode* root, int& maxVal)
    {
        if(root == NULL)
        {
            return true;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            maxVal ++;
            return true;
        }
        
        bool left, right;
        
        left = countSubtrees(root->left, maxVal);
        right = countSubtrees(root->right, maxVal);
        
        if(root->left == NULL && right)
        {
            if(root->val == root->right->val)
            {
                maxVal ++;
                return true;
            }
            else
            return false;
        }
        
        if(root->right == NULL && left)
        {
            if(root->val == root->left->val)
            {
                maxVal ++;
                return true;
            }
            else
            {
                return false;
            }
        }
        
        if(left && right && root->val == root->left->val && root->val == root->right->val)
        {
            maxVal ++;
            return true;
        }

        return false;
    }
};