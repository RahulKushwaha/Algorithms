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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() == 0 || postorder.size() == 0)
        {
            return NULL;
        }
        
        int index = postorder.size() - 1;
        
        return buildTree(inorder, postorder, 0, index, index);
    }
    
    int find(vector<int>& inorder, int l, int h, int target)
    {
        int index;
        for(int i = l; i <= h; i ++)
        {
            if(inorder[i] == target)
            {
                index = i;
                break;
            }
        }
        
        return index;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder, int l, int h, int& index)
    {
        if(l > h)
        {
            return NULL;
        }
        
        if(l == h)
        {
            TreeNode * root = new TreeNode(postorder[index--]);
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        
        int rootVal = postorder[index--];
        int rootIndex = find(inorder, l, h, rootVal);
        
        TreeNode * root = new TreeNode(rootVal);
        root->right = buildTree(inorder, postorder, rootIndex + 1, h, index);
        root->left = buildTree(inorder, postorder, l, rootIndex - 1, index);
        
        return root;
    }
};