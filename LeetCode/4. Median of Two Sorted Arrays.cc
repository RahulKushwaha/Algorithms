class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int lengthA = nums1.size();
        int lengthB = nums2.size();
        if(lengthA == 0 && lengthB == 0)
        {
            return 0;
        }

        int k = lengthA + lengthB;
        bool odd = k % 2 == 1;
        
        k = k / 2;
        if(odd)
        {
            k ++;
        }
        
        int lower = max(0, k - lengthB);
        int upper = min(lengthA, k);
        
        while(lower <= upper)
        {
            int x = ((upper - lower) / 2) + lower;
            int r1  = x >= lengthA ? INT_MAX : nums1[x];
            int l1 = x - 1 >= 0 ? nums1[x - 1] : INT_MIN;
            int r2 = k - x >= lengthB ? INT_MAX : nums2[k - x];
            int l2 = k - x - 1 >= 0 ? nums2[k - x - 1] : INT_MIN;
            
            if(r1 < l2)
            {
                lower = x + 1;
            }
            else if(l1 > r2)
            {
                upper = x - 1;
            }
            else
            {
                if(odd)
                {
                    return max(l1, l2);
                }
                
                return ((double)(max(l1, l2) + min(r1, r2))) / 2;
            }
        }
        
        return 0;
    }
};