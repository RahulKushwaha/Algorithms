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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> output;
        
        PreOrderTraversal(root, output);
        
        return output;
    }
    
    void PreOrderTraversal(TreeNode * root, vector<int>& output)
    {
        if(root == NULL)
        {
            return;
        }
        
        stack<TreeNode*> elements;
        
        TreeNode* currentNode = root;
        while(currentNode)
        {
            elements.push(currentNode);
            currentNode = currentNode->left;
        }
        
        while(elements.empty() == false)
        {
            currentNode = elements.top();
            output.push_back(currentNode->val);
            elements.pop();
            
            if(currentNode->right)
            {
                currentNode = currentNode->right;
                while(currentNode)
                {
                    elements.push(currentNode);
                    currentNode = currentNode->left;
                }
            }
        }
    }
};