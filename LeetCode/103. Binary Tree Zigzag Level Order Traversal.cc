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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> output; 
        
        if(root != NULL)
        {
            queue<TreeNode*> q1;
            queue<TreeNode*> q2;
            queue<TreeNode*> * currentQueue;
            queue<TreeNode*> * nextQueue;
            
            q1.push(root);
            currentQueue = &q1;
            nextQueue = &q2;
            vector<int> level;
            bool left = false;
            
            while(currentQueue->empty() == false)
            {
                TreeNode* currentNode = currentQueue->front();
                if(currentNode->left != NULL)
                {
                    nextQueue->push(currentNode->left);
                }
                
                if(currentNode->right != NULL)
                {
                    nextQueue->push(currentNode->right);
                }
                
                if(left)
                {
                    level.insert(level.begin(), currentNode->val);
                }
                else
                {
                    level.push_back(currentNode->val);
                }
                
                currentQueue->pop();
                
                if(currentQueue->empty())
                {
                    output.push_back(level);
                    level.clear();
                    left = left ? false : true;
                    
                    if(currentQueue == &q1)
                    {
                        currentQueue =  &q2;
                        nextQueue = &q1;
                    }
                    else
                    {
                        currentQueue = &q1;
                        nextQueue = &q2;
                    }
                }
            }
        }
        
        return output;
    }
};