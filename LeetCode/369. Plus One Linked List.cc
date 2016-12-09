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
    ListNode* reverse(ListNode* head)
    {
        ListNode * current = head; 
        ListNode * prev = NULL;
        ListNode ** newHead = &prev;
        
        while(current)
        {
            ListNode * temp = current->next;
            current->next = prev;
            prev = current;
            
            current = temp;
        }
        
        return *newHead;
    }
    
    ListNode* plusOne(ListNode* head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        ListNode * newHead = reverse(head);
        ListNode * currentNode = newHead;
        ListNode * prev = currentNode;
        
        currentNode->val ++;
        
        int carry = 0;
        while(currentNode)
        {
            currentNode->val  += carry;
            carry = currentNode->val / 10;
            currentNode->val %= 10;
            prev = currentNode;            
            currentNode = currentNode->next;
        }
        
        currentNode = prev;
        
        while(carry != 0)
        {
            ListNode* newNode = new ListNode(carry);
            carry = newNode->val / 10;
            newNode->val %= 10;
            
            currentNode->next = newNode;
            currentNode = newNode;
        }
        
        newHead = reverse(newHead);
        
        return newHead;
    }
};