class NumArray {
public:
    int * bit;
    int * input;
    int length;
    NumArray(vector<int> &nums) {
        length = nums.size();
        
        if(length == 0)
        {
            bit = NULL;
            input = NULL;
            return;
        }
        
        bit = new int[length + 1];
        input = new int[length];
        for(int i = 0; i < length; i ++)
        {
            bit[i] = 0;
            input[i] = 0;
        }
        
        bit[length] = 0;
        
        for(int i = 0; i < length; i ++)
        {
            update(i, nums[i]);
        }
        
        for(int i = 0; i < length; i ++)
        {
            input[i] = nums[i];
        }
    }

    void update(int i, int val) {
        int diff = val - input[i];
        input[i] = val;
        i ++;
        while(i <= length)
        {
            bit[i] += diff;
            i = i + (i & (-i));
        }
    }
    
    int sum(int i)
    {
        int total = 0;
        i ++;
        while(i != 0)
        {
            total += bit[i];
            i = i - (i & (-i));
        }
        
        return total;
    }

    int sumRange(int i, int j) {
        return sum(j) - sum(i - 1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);