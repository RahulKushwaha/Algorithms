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
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> output;
        if(root == NULL)
        {
            return output;
        }
        
        int depth = findMaxDepth(root);
        output.resize(depth);
        
        findLeaves(root, depth, output, depth);
        
        return output;
    }
    
    void findLeaves(TreeNode* root, int& depth, vector<vector<int>>& output, int maxDepth)
    {
        if(root == NULL)
        {
            depth --;
            return;
        }
        
        int newDepth1 = depth, newDepth2 = depth;
        findLeaves(root->left, newDepth1, output, maxDepth);
        findLeaves(root->right, newDepth2, output, maxDepth);
        
        depth = min(newDepth1, newDepth2);
        
        output[maxDepth - depth - 1].insert(output[maxDepth - depth - 1].begin(), root->val);
        
        depth --;
    }
    
    int findMaxDepth(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int left = findMaxDepth(root->left) + 1;
        int right = findMaxDepth(root->right) + 1;
        
        return max(left, right);
    }
};