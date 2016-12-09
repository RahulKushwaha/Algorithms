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
    ListNode* partition(ListNode* head, int x) {
        ListNode* auxHeadNode = new ListNode(-1);
        ListNode* newList = new ListNode(-1);
        
        auxHeadNode->next = head;
        
        ListNode* currentNode = head;
        ListNode* prev = auxHeadNode;
        ListNode* newListHead = newList;
        
        while(currentNode)
        {
            if(currentNode->val >= x)
            {
                newListHead->next = currentNode;
                newListHead = newListHead->next; 
                prev->next = currentNode->next;
                currentNode->next = NULL;
                currentNode = prev->next;
            }
            else
            {
                prev = currentNode;
                currentNode = currentNode->next;
            }
        }
        
        prev->next = newList->next;
        newListHead = auxHeadNode->next;
        
        delete newList;
        delete auxHeadNode;
        
        return auxHeadNode->next;
    }
};