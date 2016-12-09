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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> output;
        
        if(root == NULL)
        {
            return output; 
        }
        
        binaryTreePaths(root, "", output);
        
        return output;
    }
    
    void binaryTreePaths (TreeNode * root, string s, vector<string> & output)
    {
        if(root == NULL)
        {
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            s += "->" + to_string(root->val);
            
            s = s.substr(2);
            output.push_back(s);
        }
        
        s += "->" + to_string(root->val);
        binaryTreePaths(root->left, s, output);
        binaryTreePaths(root->right, s, output);
    }
};