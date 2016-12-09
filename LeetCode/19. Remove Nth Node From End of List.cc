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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
        {
            return head;
        }
        
        int counter = 1;
        ListNode * fast = head;
        
        while(counter < n && fast)
        {
            fast = fast->next;
            counter ++;
        }
        
        ListNode * slow = head;
        ListNode * prev = head;
        
        while(fast->next != NULL)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next;
        }
        
        if(slow == head)
        {
            head = head->next;
            
        }
        else
        {
            prev->next = prev->next->next;
        }
        
        return head;
    }
};