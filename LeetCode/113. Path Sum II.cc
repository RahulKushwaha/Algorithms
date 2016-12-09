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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> output; 
        
        if(root == NULL)
        {
            return output;
        }
        
        vector<int> pathElements;
        
        pathSum(root, sum, 0, pathElements, output);
        
        return output;
    }
    
    void pathSum(TreeNode * root, int sum, int currentSum, vector<int> pathElements, vector<vector<int>>& output)
    {
        if(root == NULL)
        {
            return ;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            if(currentSum + root->val == sum)
            {
                pathElements.push_back(root->val);
                output.push_back(pathElements);
            }
            
            return;
        }
        
        pathElements.push_back(root->val);
        pathSum(root->left, sum, currentSum + root->val, pathElements, output);
        pathSum(root->right, sum, currentSum + root->val, pathElements, output);
    }
};