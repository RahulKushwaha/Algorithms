/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode*> nodes;
    BSTIterator(TreeNode *root) {
        while(root)
        {
            nodes.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return nodes.empty() == false;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode * top = nodes.top();
        nodes.pop();
        TreeNode * currentNode = top;
        
        if(currentNode->right != NULL)
        {
            currentNode = currentNode->right;
            while(currentNode)
            {
                nodes.push(currentNode);
                currentNode = currentNode->left;
            }
        }
        
        return top->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */