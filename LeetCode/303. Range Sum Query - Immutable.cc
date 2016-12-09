class NumArray {
public:
    vector<int> lookup;
    NumArray(vector<int> &nums) {
        int size = nums.size();
        lookup.resize(size);
        
        int runningSum = 0;
        int counter = 0;
        for(vector<int>::iterator i = nums.begin(); i != nums.end(); i ++)
        {
            runningSum += *i;
            lookup[counter++] = runningSum;
        }
    }

    int sumRange(int i, int j) {
        if(i == 0)
        {
            return lookup[j];
        }
        
        return lookup[j] - lookup[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);