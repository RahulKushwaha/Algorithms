// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        if(n <= 0)
        {
            return 0;
        }
        
        int l = 0, u = n;
        int result;
        while(l <= u)
        {
            int mid = ((u - l) / 2) + l;
            if(isBadVersion(mid))
            {
                result = mid;
                if(l == u)
                {
                    break;
                }
                
                u = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return result;
    }
};