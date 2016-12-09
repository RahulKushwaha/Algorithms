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

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> output;
        
        if(root == NULL)
        {
            return output;
        }
        
        stack<TreeNode*> s1;
        stack<int> s2;
        s1.push(root);
        TreeNode * currentNode = root;
        
        while(s1.empty() == false)
        {
            currentNode = s1.top();
            s2.push(currentNode->val);
            s1.pop();
            
            if(currentNode->left != NULL)
            {
                s1.push(currentNode->left);
            }
            
            if(currentNode->right != NULL)
            {
                s1.push(currentNode->right);
            }
            
        }
        
        while(s2.empty() == false)
        {
            output.push_back(s2.top());
            s2.pop();
        }
        
        return output;
    }
};