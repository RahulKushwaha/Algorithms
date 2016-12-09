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
    int minDepth(TreeNode* root) {
        
        if(root == NULL)
        {
            return 0;
        }
        
        int result = INT_MAX;
        
        minDepth(root, 0, result);
        
        return result;
    }
    
    void minDepth(TreeNode * root, int h, int& min)
    {
        if(root == NULL)
        {
            return ;
        }
        
        if(root != NULL && root->left == NULL && root->right == NULL)
        {
            h ++;
            if(h < min)
            {
                min = h;
            }
            
            return;
        }
        
        minDepth(root->left, h + 1, min);
        minDepth(root->right, h + 1, min);
    }
};