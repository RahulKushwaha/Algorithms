/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }
        
        RandomListNode* node = head;
        while(node)
        {
            RandomListNode* nextNode = node->next;
            RandomListNode* newNode = new RandomListNode(node->label);
            newNode->next = nextNode;
            node->next = newNode;
            
            node = nextNode;
        }
        
        RandomListNode* prev = NULL;
        RandomListNode* newListNode = head->next;
        prev = head;
        node = NULL;
        
        while(prev)
        {
            node = prev->next;
            if(prev->random)
            {
                node->random = prev->random->next;
            }
            
            prev = node->next;
        }
        
        prev = head;
        node = new RandomListNode(-1);
        RandomListNode * sentinel  = node;
        while(prev)
        {
            node->next = prev->next;
            node = prev->next;
            prev->next = node->next;
            
            prev = node->next;
        }
        
        return newListNode;
    }
};