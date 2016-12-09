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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = NULL, *current = head;
        
        while(current != NULL)
        {
            ListNode * temp = current->next;
            current->next = prev;
            
            prev = current;
            current = temp;
        }
        
        return prev;
    }
};