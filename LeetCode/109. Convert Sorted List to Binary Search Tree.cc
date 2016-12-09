/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    int listLength(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            head = head->next;
            length ++;
        }
        
        return length;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        int length = listLength(head);
        
        if(length == 0)
        {
            return NULL;
        }
        
        return sortedList(head, 1, length);
    }
    
    TreeNode* sortedList(ListNode* head, int l, int h)
    {
        if(l > h)
        {
            return NULL;
        }
        
        int mid = ((h - l) / 2) + l;
        
        int counter = l ;
        ListNode* currentNode = head;
        while(counter < mid)
        {
            currentNode = currentNode->next;
            counter ++;
        }
        
        cout<<currentNode->val<<endl;
        
        TreeNode* node = new TreeNode(currentNode->val);
        node->left = sortedList(head, l, mid - 1);
        if(currentNode->next)
        {
            node->right = sortedList(currentNode->next, mid + 1, h);
        }
        
        return node;
    }
};