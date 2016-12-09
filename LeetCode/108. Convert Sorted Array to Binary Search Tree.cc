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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int l = 0; 
        int u = nums.size() - 1;
        
        return CreateTree(nums, l, u);
        
    }
    
    TreeNode * CreateTree(vector<int>& nums, int l, int u)
    {
        if(l > u)
        { 
            return NULL;
        }
        
        int mid = ((u - l) / 2) + l;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = CreateTree(nums, l, mid - 1);
        root->right = CreateTree(nums, mid + 1, u);
        
        return root;
    }
};