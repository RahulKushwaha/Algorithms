class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int length = nums.size();
        vector<int> output;
        if(length == 0)
        {
            return output;
        }
        
        output.resize(length);
        int index = length - 1;
        
        int * input = &nums[0];
        
        int i = 0, j = length - 1;
        
        if(a > 0)
        {
            while(i > j == false)
            {
                int max1 = transform(a, b, c, input[i]);
                int max2 = transform(a, b, c, input[j]);
                
                if(max1 > max2)
                {
                    i ++;
                    output[index--] = max1;
                }
                else
                {
                    j--;
                    output[index--] = max2;
                }
            }
        }
        else
        {
            index = 0;
            while(i > j == false)
            {
                int min1 = transform(a, b, c, input[i]);
                int min2 = transform(a, b, c, input[j]);
                
                if(min1 < min2)
                {
                    i ++;
                    output[index++] = min1;
                }
                else
                {
                    j--;
                    output[index++] = min2;
                }
            }
        }
        
        
        return output;
    }
    
    int transform(int a, int b, int c, int x)
    {
        return a * x * x + b * x + c;
    }
};