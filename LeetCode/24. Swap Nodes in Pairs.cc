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
    ListNode* swapPairs(ListNode* head) {
        
        ListNode* node1 = head, *node2, *temp;
        ListNode* prev = NULL;
        while(node1)
        {
            node2 = node1->next;
            
            if(node2 == NULL)
            {
                break;
            }
            
            temp = node2->next;
            
            node1->next = node2->next;
            node2->next = node1;
            
            if(prev == NULL)
            {
                head = node2;
            }
            else
            {
                prev->next = node2;
            }
            
            prev = node1;
            
            node1 = temp;
        }
        
        return head;
    }
};