/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL)
        {
            return NULL;
        }
        
        // Remove all the elements which are at the head and equal to val
        while(head && head->val == val)
        {
            head = head->next;
        }
        
        ListNode * current = head;
        ListNode * prev = head;
        
        while(current)
        {
            if(current->val == val)
            {
                prev->next = current->next;
            }
            else
            {
                prev = current;
            }
            
            current = current->next;
        }
        
        return head;
    }
};