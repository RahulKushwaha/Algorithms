/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
bool compare(ListNode* x, ListNode* y)
{
    return x->val > y->val;    
}

class Solution {
private:
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0)
        {
            return NULL;
        }
        
        if(size == 1)
        {
            return lists[0];
        }
        
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq(compare);
        
        for(int i = 0; i < size; i ++)
        {
            if(lists[i] != NULL)
            {
                pq.push(lists[i]);
            }
        }
        
        if(pq.empty())
        {
            return NULL;
        }
        
        ListNode * currentNode = NULL;
        ListNode *head = new ListNode(-1);
        currentNode = head;
        
        while(pq.empty() == false)
        {
            ListNode * temp = pq.top();
            
            currentNode->next = temp;
            currentNode = currentNode->next;
            
            pq.pop();
            
            if(temp->next != NULL)
            {
                pq.push(temp->next);
            }
        }
        
        return head->next;
    }
};