typedef unsigned long long ull;
class Solution {
public:
    bool isAdditiveNumber(string num) {
        return isAdditiveNumber(num, 0, 0, 0, 0);
    }
    
    bool isAdditiveNumber(string& num, ull index, ull prev2, ull prev1, ull partitions)
    {
        if(index == num.size() && partitions >= 3)
        {
            return true;
        }

        ull currentNum = 0;
        for(int i = index; i < num.size(); i ++)
        {
            currentNum *= 10;
            currentNum += num[i] - '0';
            if(currentNum == prev1 + prev2 || partitions < 2)
            {
                if(isAdditiveNumber(num, i + 1, prev1, currentNum, partitions + 1))
                {
                    return true;
                }
            }
            
            if(num[index] == '0')
            {
                break;
            }
        }
        
        return false;
    }
};