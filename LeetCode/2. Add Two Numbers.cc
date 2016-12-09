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
    int length(ListNode * list)
    {
        if(list == NULL)
        {
            return 0;
        }
        
        int counter = 0;
        while(list)
        {
            counter ++;
            list = list->next;
        }
        
        return counter;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL || l2 == NULL)
        {
            return l1 == NULL ? l2 : l1;   
        }
        
        if(length(l1) < length(l2))
        {
            ListNode* temp = l1;
            l1 = l2;
            l2 = temp;
        }
        
        int carry = 0;
        ListNode* newList = l1;
        
        ListNode* prev = l1;
        while(l1 && l2)
        {
            int temp = l1->val + l2->val + carry;
            carry = temp / 10;
            l1->val = temp % 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        
        if(l1 != NULL)
        {
            prev = l1;
            while(l1 != NULL && carry != 0)
            {
                int temp = l1->val + carry;
                carry = temp / 10;
                l1->val = temp % 10;
                prev = l1;
                l1 = l1->next;
            }
        }
        
        l1 = prev;
        while(carry != 0)
        {
            int val = carry % 10;
            ListNode* newNode = new ListNode(val);
            newNode->next = NULL;
            l1->next = newNode;
            l1 = newNode;
            carry = carry / 10;
        }
        
        return newList;
    }
};