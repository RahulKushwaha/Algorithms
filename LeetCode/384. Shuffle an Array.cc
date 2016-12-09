class Solution {
public:
    vector<int> input;
    int length;
    
    Solution(vector<int> nums): input(nums), length(nums.size()) {
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return input;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> output(input);
        int offset = 0;
        while(offset != length)
        {
            int randomIndex = rand() % (length - offset);
            swap(output[randomIndex + offset], output[offset]);
            offset ++;
        }
        
        return output;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */