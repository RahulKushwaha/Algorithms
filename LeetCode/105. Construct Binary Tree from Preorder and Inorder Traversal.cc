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

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(preorder.size() == 0 || inorder.size() == 0 )
        {
            return NULL;
        }
        
        int index = 0;
        return buildTree(preorder, inorder, 0, inorder.size() - 1, index);
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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int l, int h, int& index)
    {
        if(l > h)
        {
            return NULL;
        }
        
        if(l == h)
        {
            TreeNode* root = new TreeNode(preorder[index]);
            root->left = NULL;
            root->right = NULL;
            index ++;
            return root;
        }
        
        int rootVal = preorder[index];
        int rootIndex = find(inorder, l, h, rootVal);
        
        index ++;
        TreeNode * root = new TreeNode(rootVal);
        root->left = buildTree(preorder, inorder, l, rootIndex - 1, index);
        root->right = buildTree(preorder, inorder, rootIndex + 1, h, index);
        
        return root;
    }
};