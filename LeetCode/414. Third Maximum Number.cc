class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int m1 = INT_MIN, m2 = INT_MIN, m3 = INT_MIN;
        int length = nums.size();
        unordered_set<int> distinctNumbers;
        
        for(int i = 0; i < length; i ++)
        {
            int & num = nums[i];
            pair<unordered_set<int>::iterator, bool> ret = distinctNumbers.insert(num);
            if(ret.second == false)
            {
                continue;
            }
            
            if(m1 < num)
            {
                m3 = m2;
                m2 = m1;
                m1 = num;
            }
            else if(m2 < num)
            {
                m3 = m2;
                m2 = num;
            }
            else if(m3 < num)
            {
                m3 = num;
            }
        }
        
        if(distinctNumbers.size() >= 3)
        {
            return m3;
        }
        
        return m1;
    }
};