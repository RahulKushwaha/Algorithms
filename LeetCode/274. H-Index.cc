class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        if(length == 0)
        {
            return 0;
        }
        
        sort(citations.begin(), citations.end());
        
        int * input = &citations[0];
        int i = length - 1;
        int counter = 0;
        while(i >= 0)
        {
            if(input[i] > counter)
            {
                counter ++;
                i--;
            }
            else
            {
                break;
            }
        }
        
        return counter;
    }
};