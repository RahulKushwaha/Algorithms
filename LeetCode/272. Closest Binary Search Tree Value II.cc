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
    stack<TreeNode*> successorStack;
    stack<TreeNode*> predecessorStack;
    
    bool hasPredecessor()
    {
        return predecessorStack.empty() == false;
    }
    
    bool hasSuccessor()
    {
        return successorStack.empty() == false;
    }
    
    int getSuccessor()
    {
        TreeNode* top = successorStack.top();
        int result = top->val;
        successorStack.pop();
        
        if(top->right)
        {
            TreeNode* currentNode = top->right;
            while(currentNode)
            {
                successorStack.push(currentNode);
                currentNode = currentNode->left;
            }
        }
        
        return result;        
    }
    
    int peekSucessor()
    {
        TreeNode* top = successorStack.top();
        return top->val;
    }
    
    int getPredecessor()
    {
        TreeNode* top = predecessorStack.top();
        int result = top->val;
        predecessorStack.pop();
        
        if(top->left)
        {
            TreeNode* currentNode = top->left;
            while(currentNode)
            {
                predecessorStack.push(currentNode);
                currentNode = currentNode->right;
            }
        }
        
        return result;
    }
    
    int peekPredecessor()
    {
        TreeNode* top = predecessorStack.top();
        return top->val;
    }
    
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> output;
        if(root == NULL)
        {
            return output;
        }
        
        TreeNode* currentNode = root;
        while(currentNode)
        {
            if(currentNode->val < target)
            {
                predecessorStack.push(currentNode);
                currentNode = currentNode->right;
            }
            else
            {
                successorStack.push(currentNode);
                currentNode = currentNode->left;
            }
        }

        for(int i = 0; i < k; i ++)
        {
            bool predecessorPresent = hasPredecessor();
            bool sucessorPresent = hasSuccessor();
            if(predecessorPresent && sucessorPresent)
            {
                int successor = peekSucessor();
                int predecessor = peekPredecessor();
                if(successor - target < target - predecessor)
                {
                    getSuccessor();
                    output.push_back(successor);
                }
                else
                {
                    getPredecessor();
                    output.insert(output.begin(), predecessor);
                }
            }
            else if(predecessorPresent)
            {
                output.insert(output.begin(), getPredecessor());
            }
            else
            {
                output.push_back(getSuccessor());
            }
        }
        
        return output;
    }
};