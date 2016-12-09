/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Note: Please read a modification of BST which allows log(n) rank finding.
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result;
        kthSmallest(root, k, result);
        
        return result;
    }
    
    void kthSmallest(TreeNode * root, int& k, int & result)
    {
        if(root == NULL)
        {
            return;
        }
        
        kthSmallest(root->left, k, result);
        k--;
        if(k == 0)
        {
            result = root->val;
            return;
        }
        
        kthSmallest(root->right, k, result);
    }
};