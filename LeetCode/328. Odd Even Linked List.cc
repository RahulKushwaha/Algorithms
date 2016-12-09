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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }
        
        ListNode* newHead1 = head;
        ListNode* newHead2 = head->next;
        
        ListNode* currentNode1 = newHead1, *currentNode2 = newHead2, *prev = newHead1;
        
        while(currentNode1 && currentNode2)
        {
            currentNode1->next = currentNode2->next;
            prev = currentNode1;
            currentNode1 = currentNode1->next;
            
            if(currentNode1)
            {
                currentNode2->next = currentNode1->next;
                currentNode2 = currentNode2->next;
            }
        }
        
        if(currentNode1)
        {
            prev = currentNode1;
        }
        
        prev->next = newHead2;
        
        return head;
    }
};