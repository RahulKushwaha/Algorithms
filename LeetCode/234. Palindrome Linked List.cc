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
    int listLength(ListNode* head)
    {
        int length = 0;
        while(head)
        {
            head = head->next;
            length ++;
        }
        
        return length;
    }
    
    bool isPalindrome(ListNode* head) {
        int length = listLength(head);
        if(length <= 1)
        {
            return true;
        }
        
        ListNode* fast = head;
        ListNode* slow = head;
        
        int mid = ceil(length / 2);
        
        while(mid != 0)
        {
            fast = fast->next;
            mid --;
        }
        
        ListNode* currentNode = fast;
        ListNode* prev = NULL;
        
        while(currentNode)
        {
            ListNode* temp = currentNode->next;
            currentNode->next = prev;
            prev = currentNode;
            currentNode = temp;
        }
        
        currentNode = prev;
        while(currentNode)
        {
            if(head->val != currentNode->val)    
            {
                return false;
            }
            
            head = head->next;
            currentNode = currentNode->next;
        }
        
        return true;
    }
};