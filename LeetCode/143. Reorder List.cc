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
    int lengthList(ListNode* head)
    {
        int count = 0;
        while(head)
        {
            head = head->next;
            count++;
        }
        
        return count;
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        while(head)
        {
            ListNode* temp = head->next;
            head->next = prev;
            prev = head;
            
            head = temp;
        }
        
        return prev;
    }
    
    void reorderList(ListNode* head) {
        int length = lengthList(head);
        
        if(length <= 2)
        {
            return;
        }
        
        ListNode* prev = head, *currentNode = head;
        for(int i = 0; i < floor(length / 2); i ++)
        {
            prev = currentNode;
            currentNode = currentNode->next;
        }
        
        prev->next = NULL;
        
        ListNode* secondList = reverse(currentNode);
        ListNode* firstList = head;
        
        ListNode* newList = new ListNode(10);
        head = newList;
        
        int i = 0;
        while(secondList &&  firstList)
        {
            ListNode * temp;
            if(i % 2 == 0)
            {
                temp = firstList->next;
                newList->next = firstList;
                firstList = temp;
            }
            else
            {
                temp = secondList->next;
                newList->next = secondList;
                secondList = temp;
            }
            
            newList = newList->next;
            newList->next = NULL;
            
            i ++;
        }
        
        if(secondList)
        {
            newList->next = secondList;
        }
        
        if(firstList)
        {
            newList->next = firstList;
        }
        
        head = head->next;
    }
};