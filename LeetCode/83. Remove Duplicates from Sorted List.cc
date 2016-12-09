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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
        {
            return head;
        }
        
        ListNode * prev = head;
        
        if(head->next == NULL)
        {
            return head;    
        }
        
        ListNode * current = head->next;
        
        while(current != NULL)
        {
            if(current->val == prev->val)
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