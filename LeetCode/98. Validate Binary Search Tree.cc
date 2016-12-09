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
    bool isValidBST(TreeNode* root) {
        TreeNode* nullNode = NULL;
        return isValid(root, nullNode);
    }
    
    bool isValid(TreeNode * root, TreeNode*& prev)
    {
        if(root == NULL)
        {
            return true;
        }

        bool valid = isValid(root->left, prev);
        
        if(valid == false)
        {
            return false;
        }
        
        if(prev != NULL && prev->val >= root->val)
        {
            return false;
        }
        
        prev = root;

        return isValid(root->right, prev);
    }
};