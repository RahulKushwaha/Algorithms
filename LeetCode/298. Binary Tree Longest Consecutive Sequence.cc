int Max(int a , int b)
{
    return a > b ? a : b;
}

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
    int longestConsecutive(TreeNode* root) {
        int max = 0;
        
        longestConsecutive(root, max, 0);
        
        return max;
    }
    
    void longestConsecutive(TreeNode* root, int& max, int current)
    {
        if(root == NULL)
        {
            return;
        }
        
        current ++;
        max = Max(max, current);
        
        if(root->left != NULL)
        {
            longestConsecutive(root->left, max, root->left->val == root->val + 1 ? current : 0);
        }
        
        if(root->right != NULL)
        {
            longestConsecutive(root->right, max, root->right->val == root->val + 1 ? current : 0);
        }
    }
};