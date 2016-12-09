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
    void reverse(ListNode** head, ListNode** end)
    {
        ListNode* currentNode = *head;
        ListNode * newEnd = *head;
        ListNode* prev = NULL;
        while(currentNode)
        {
            ListNode * temp = currentNode->next;
            currentNode->next = prev;
            prev = currentNode;
            currentNode = temp;
        }
        
        *head = prev;
        *end = newEnd;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k == 1)
        {
            return head;
        }
        
        ListNode* newHead = new ListNode(-1);
        ListNode* prev = newHead;
        ListNode * currentNode = head;
        while(currentNode)
        {
            ListNode* segment = currentNode;
            int i = 0;
            for(; i < k - 1 && currentNode ->next; i ++)
            {
                currentNode = currentNode->next;
            }
            
            ListNode* temp = currentNode->next;
            currentNode->next = NULL;
            
            if(i == k - 1)
            {
                reverse(&segment, &currentNode);
            }
            
            prev->next = segment;
            prev = currentNode;
            
            currentNode->next = temp;
            currentNode = temp;
        }

        head = newHead->next;
        
        return head;
    }
};