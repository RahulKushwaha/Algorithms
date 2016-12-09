/*
This problem is to find arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1; I think the key point is how we solve it in the O(n) time complexity and O(1) space complexity.
Let's think about find two number, two number is so clear, you define a variable min and then you iterate the array, if you find a number is less than the min, you update the min to the cur number, if you find the number is more than the min, then you get the solution and return true.
For example, 10 8 7 6 5 2 3 4
For the start the min = 10, and we iterate the array from index 1, 8 is less than 10, we just update the min, which means the min is 8 ... util we meet 2, 2 is less than min 5, and update min to 2, finally we meet 3, apparently, bigger than 2, so we found two number and return true;
So let's do three number, we can define min and secondMin, min is array[0], secondMin is MAX_VALUE(why, the code will show you); the same idea, we iterate the array from index 1, while we meet the number is bigger than secondMin, that means we found three numbers(now you can know why secondMin should be MAX_VALUE) ,else if the number is bigger than min and less than secondMin ,we should update secondMin to the number. else if the number is less than min, that we can update min to the number.
For example, 7 2 9 6 1 4 6
the first min is 7, and then iterate the array, 2 is less than the min, so update. 9 is bigger than min and smaller than secondMin(initially is MAX_VALUE), the secondMin update to 9,next we meet 6, according to above rules, we update secondMin to 6. and then we meet 1, 1 is smaller than min, we update min to the 1(if you are wonder why min can after the secondMin, you can think that if the next is bigger than secondMin, we can return true , it does't matter with min, else we get the smaller two number), when we meet 4, we update secondMin to 4 (before two number is 2 6 and then is 1 4) ,and finally, we meet 6 ,return true;
*/
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int length = nums.size();
        
        if(length < 3)
        {
            return false;
        }
        
        int dp[3];
        for(int i = 0; i < 3; i ++)
        {
            dp[i] = INT_MAX;
        }
        
        int* input = &nums[0];
        
        for(int i = 0; i < length; i ++)
        {
            int j = 0;
            for(; j < 3; j ++)
            {
                if(input[i] <= dp[j])
                {
                    dp[j] = input[i];
                    if(j == 2)
                    {
                        return true;
                    }
                    
                    break;
                }
            }
        }
        
        return false;
    }
};