struct bst 
{
    int val;
    bst* left;
    bst* right;
    int nodesCount;
    
    bst(int val): val(val), left(NULL), right(NULL), nodesCount(1)
    {
        
    }
};

class Solution {
public:

    bool add(bst** root, int val, int index, vector<int>& output)
    {
        if(*root == NULL)
        {
            *root = new bst(val);
            return true;
        }
        
        bst* currentNode = *root;
        bst* prev = NULL;
        while(currentNode)
        {
            prev = currentNode;
            if(currentNode->val < val)
            {
                output[index] += currentNode->nodesCount;
                currentNode = currentNode->right;
            }
            else
            {
                currentNode->nodesCount ++;
                currentNode = currentNode->left;
            }
        }
        
        if(prev->val < val)
        {
            prev->right = new bst(val);
        }
        else
        {
            prev->left = new bst(val);
        }
        
        return true;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> output;
        int length = nums.size();
        if(length == 0)
        {
            return output;
        }
        
        output.resize(length, 0);
        
        bst* root = NULL;
        
        for(int i = length - 1; i >= 0; i --)
        {
            add(&root, nums[i], i, output);
        }
        
        return output;
    }
};