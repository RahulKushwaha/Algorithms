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

    int length(ListNode * head)
    {
        if(head == NULL)
        {
            return 0;
        }
        
        int counter = 1;
        while(head != NULL)
        {
            head = head->next;
            counter ++;
        }
        
        return counter;
    }
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        
        int lengthA = length(headA);
        int lengthB = length(headB);
        if(lengthB > lengthA)
        {
            swap(headA, headB);
            swap(lengthA, lengthB);
        }
        
        int diff = lengthA - lengthB;
        
        int counter = 0;
        while(counter < diff)
        {
            counter ++; 
            headA = headA->next;
        }
        
        while(headA && headB)
        {
            if(headA == headB)
            {
                return headA;
            }
            
            headA = headA->next;
            headB = headB->next;
        }
        
        return NULL;
    }
};