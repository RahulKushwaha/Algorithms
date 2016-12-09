/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return;
        TreeLinkNode dummy(0);
        TreeLinkNode *head = &dummy;
        TreeLinkNode *curr = root;
        while(curr){
            if(curr->left) {
                head->next = curr->left;
                head = head->next;
            }
            if(curr->right) {
                head->next = curr->right;
                head = head->next;
            }
            curr = curr->next;
        }

        connect(dummy.next);
    }
};