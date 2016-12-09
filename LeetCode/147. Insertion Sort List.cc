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
    
    void insert(ListNode**head, ListNode * node)
    {
        ListNode* currentNode = *head;
        ListNode* prev = NULL;
        while(currentNode)
        {
            if(node->val < currentNode->val)
            {
                break;
            }
            
            prev = currentNode;
            currentNode = currentNode->next;
        }
        
        if(prev == NULL)
        {
            node->next = *head;
            *head  = node;
        }
        else
        {
            ListNode* temp = prev->next;
            prev->next = node;
            node->next = temp;
        }
    }
    
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode* currentNode = head->next;
        head->next = NULL;
        
        while(currentNode)
        {
            ListNode* temp = currentNode->next;
            insert(&head, currentNode);
            currentNode = temp;
        }
        
        return head;
    }
};