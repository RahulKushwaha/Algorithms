class Solution {
public:
    vector<int> input;
    int length;
    Solution(vector<int> nums): input(nums), length(nums.size()) {
        srand(time(NULL));
    }
    
    int pick(int target) {
        
        int counter = 0;
        int output = -1;
        for(int i = 0; i < length; i ++)
        {
            if(input[i] == target)
            {
                counter ++;
                int index = rand() % counter;
                
                if(index == 0)
                {
                    output = i;
                }
            }
        }
        
        return output;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */