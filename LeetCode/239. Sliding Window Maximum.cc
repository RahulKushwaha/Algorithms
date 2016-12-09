class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        int size = nums.size();
        deque<int> window;

        for(int i = 0; i < size; i ++)
        {
            if(window.empty())
            {
                window.push_back(i);
            }
            else
            {
                if(i - window.front() == k)
                {
                    window.pop_front();
                }
                
                while(window.empty() == false && nums[i] > nums[window.back()])
                {
                    window.pop_back();
                }
                
                window.push_back(i);
            }
            
            if(i >= k - 1)
            {
                output.push_back(nums[window.front()]);
            }
        }
        
        return output;
    }
};