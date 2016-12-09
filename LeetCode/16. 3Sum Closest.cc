int search(int* input, int l, int u, int key, int &a, int& b)
{
    int err = INT_MAX;
    while(l < u)
    {
        int sum = input[l] + input[u];
        int currentErr = abs(key - sum);
        if(currentErr < err)
        {
            err = currentErr;
            a = l; 
            b = u;
        }
        
        if(sum > key)
        {
            u --;
        }
        else
        {
            l ++ ;
        }
    }
    
    return err;
}

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int length = nums.size();
        if(length < 3)
        {
            return 0;
        }
        
        int * input = &nums[0];
        
        sort(input, input + length);
        
        int err = INT_MAX;
        int a, b, c;
        for(int i = 0; i < length; i ++)
        {
            int key = target - input[i];
            int x, y;
            int currentErr = search(input, i + 1, length - 1, key, x, y);
            
            if(currentErr < err)
            {
                a = i;
                b = x;
                c = y;
                err = currentErr;
            }
        }
        
        return input[a] + input[b] + input[c];
    }
};