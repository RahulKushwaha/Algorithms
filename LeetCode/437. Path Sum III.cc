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
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
        {
            return 0;
        }
        
        unordered_set<TreeNode*> visited;
        vector<TreeNode*> elements;
        elements.push_back(root);
        
        int output = 0;
        while(elements.size() != 0)
        {
            TreeNode* top = elements[elements.size() - 1];
            if(top->left && visited.find(top->left) == visited.end())
            {
                elements.push_back(top->left);
                continue;
            }
            
            if(top->right && visited.find(top->right) == visited.end())
            {
                elements.push_back(top->right);
                continue;
            }
            
            visited.insert(top);
            
            int runningSum = 0;
            int length = elements.size();
            for(int i = length - 1; i >= 0; i --)
            {
                runningSum += elements[i]->val;
                if(runningSum == sum)
                {
                    output ++;
                }
            }
            
            elements.pop_back();
        }
        
        return output;
    }
};