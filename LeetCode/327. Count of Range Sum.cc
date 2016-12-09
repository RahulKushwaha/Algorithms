typedef long long ll;
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        ll length = nums.size(), output = 0, currentSum = 0;
        map<ll, int> rangeSum;
        
        for(ll num : nums)
        {
            currentSum += num;
            ll target = currentSum - upper;
            ll lowerBound = currentSum - upper;
            ll upperBound = currentSum - lower;
            
            map<ll, int>::iterator itr = rangeSum.lower_bound(target);
            while(itr != rangeSum.end())
            {
                if(itr->first >= lowerBound && itr->first <= upperBound)
                {
                    output += itr->second;
                }
                else
                {
                    break;
                }
                
                itr ++;
            }
            
            if(currentSum >= lower && currentSum <= upper)
            {
                output ++;
            }
            
            rangeSum[currentSum] ++;
        }
        
        return output;
    }
};