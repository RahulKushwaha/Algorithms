class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int length = numbers.size();
        vector<int> output;
        if(length == 0)
        {
            return output;
        }
        
        int i = 0; 
        int j = length - 1;
        
        while(i < j)
        {
            int currentSum = numbers[i] + numbers[j];
            if(currentSum == target)
            {
                output.push_back(i + 1);
                output.push_back(j + 1);
                return output;
            }
            
            if(currentSum < target)
            {
                i ++;
            }
            else
            {
                j --;
            }
        }
        
        return output;
    }
};