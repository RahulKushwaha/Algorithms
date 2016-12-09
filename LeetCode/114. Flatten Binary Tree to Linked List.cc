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
    void flatten(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }
        
        stack<TreeNode*> elements;
        elements.push(root);
        
        TreeNode * lastNode = NULL;
        
        while(elements.empty() == false)
        {
            TreeNode * currentNode = elements.top();
            elements.pop();
            
            if(currentNode->right != NULL)
            {
                elements.push(currentNode->right);
            }
            
            if(currentNode->left != NULL)
            {
                elements.push(currentNode->left);
            }
            
            currentNode->left = NULL;
            if(lastNode == NULL)
            {
                lastNode = currentNode;
            }
            else
            {
                lastNode->right = currentNode;
                lastNode = currentNode;
            }
        }
    }
};