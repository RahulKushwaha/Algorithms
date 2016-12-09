class Solution {
public:
    ListNode * listHead;
    
    /** @param head The linked list's head. Note that the head is guanranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        srand (time(NULL));
        listHead = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int count = 0;
        int ans = - 1;
        ListNode* node = listHead;
        if(node)
        {
            ans = node->val;
            node = node->next;
            count ++;
        }
        
        while(node)
        {
            count ++;
            int randomIndex = rand() % count;
            if(randomIndex == 0)
            {
                ans = node->val;
            }
            
            node = node->next;
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */