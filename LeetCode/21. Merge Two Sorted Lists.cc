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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if(l1 == NULL && l2 == NULL)
        {
            return NULL;
        }
        
        if(l1 == NULL)
        {
            return l2;
        }
        
        if(l2 == NULL)
        {
            return l1;
        }
        
        if(l2->val < l1->val)
        {
            ListNode * temp = l1;
            l1 = l2;
            l2 = temp;
        }
        
        ListNode * head = l1;
        ListNode* prev = l1;
        
        while(l1 != NULL && l2 != NULL)
        {
            if(l1->val <= l2->val)
            {
                prev = l1;
                l1 = l1->next;
            }
            else
            {
                ListNode* l2Next = l2->next;
                ListNode* l1Next = l1->next;
                l1->next = l2;
                l2->next = l1Next;
                
                l1 = l1Next;
                l2 = l2Next;
            }
        }
        
        if(l1 == NULL)
        {
            l1 = prev;
        }
        
        if(l2 != NULL)
        {
            l1->next = l2;
        }
        
        return head;
    }
};