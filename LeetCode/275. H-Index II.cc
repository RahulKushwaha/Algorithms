class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if(length == 0)
        {
            return 0;
        }
        
        int l = 0, h = length - 1; 
        
        int counter = 0;
        while(l <= h)
        {
            int mid = ((h - l) / 2) + l;
            
            if(citations[mid] >= mid + 1)
            {
                counter = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        
        return length - counter;
    }
};