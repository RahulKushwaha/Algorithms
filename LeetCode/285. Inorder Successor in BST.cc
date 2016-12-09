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
    TreeNode* minValue(TreeNode* root)
    {
        TreeNode* prev = root;
        while(root)
        {
            prev = root;
            root = root->left;
        }
        
        return prev;
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(p->right != NULL)
        {
            return minValue(p->right);
        }
        
        TreeNode* succ = NULL;
        while(root)
        {
            if(root->val < p->val)
            {
                root = root->right;
            }
            else if(root->val > p->val)
            {
                succ = root;
                root = root->left;
            }
            else
            {
                break;
            }
        }
        
        return succ;
    }
};