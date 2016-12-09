// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0;
        
        for(int i = 1; i < n; i ++)
        {
            if(knows(candidate, i))
            {
                candidate = i;
            }
        }
        
        for(int i = 0; i < n; i ++)
        {
            if(i == candidate)
            {
                continue;
            }
            
            if(knows(i, candidate) == false)
            {
                return -1;
            }
            
            if(knows(candidate, i))
            {
                return -1;
            }
        }
        
        return candidate;
    }
};