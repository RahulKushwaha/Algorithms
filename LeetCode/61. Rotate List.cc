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
    int length(ListNode * head)
    {
        if(head == NULL)
        {
            return 0;
        }
        
        int counter = 0;
        
        while(head->next != NULL)
        {
            counter ++ ;
            head = head->next;
        }
        
        return counter + 1;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
        {
            return NULL;
        }
        
        int listLength = length(head);
        
        k = k % listLength;
        
        if(k == 0)
        {
            return head;
        }
        
        int counter = 0;
        ListNode* fastNode = head;
        while(counter < k)
        {
            fastNode = fastNode->next;
            counter ++;
            if(fastNode == NULL)
            {
                return head;
            }
        }
        
        ListNode* slow = head;
        
        while(fastNode->next != NULL)
        {
            slow = slow->next;
            fastNode = fastNode->next;
        }
        
        ListNode * newHead = slow->next;
        slow->next = NULL;
        
        fastNode->next = head;
        
        return newHead;
    }
};