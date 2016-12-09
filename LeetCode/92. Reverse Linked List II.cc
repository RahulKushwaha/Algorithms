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
        ListNode* prev = NULL;
        
        while(currentNode)
        {
            ListNode* temp = currentNode->next;
            currentNode->next = prev;
            prev = currentNode;
            currentNode = temp;
        }
        
        *end = *head;
        *head = prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(head == NULL || m == n)
        {
            return head;
        }
        
        ListNode* currentNode = head;
        
        int counter = 1;
        
        ListNode* auxListHead = NULL;
        ListNode* auxListEnd = NULL;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        
        while(currentNode)
        {
            if(counter == m)
            {
                auxListHead = currentNode;
            }
            
            if(counter == n)
            {
                auxListEnd = currentNode;
                next = currentNode->next;
                auxListEnd->next = NULL;
                break;
            }
            
            if(auxListHead == NULL)
            {
                prev = currentNode;    
            }
            
            currentNode = currentNode->next;
            counter ++;
        }
        
        reverse(&auxListHead, &auxListEnd);
        
        if(prev)
        {
            prev->next = auxListHead;
        }
        else
        {
            head = auxListHead;
        }
        
        if(auxListEnd)
        {
            auxListEnd->next = next;
        }
        
        return head;
    }
};