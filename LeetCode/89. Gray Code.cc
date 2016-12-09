class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> output{0};
        int offset = 0;
        for(int i = 0; i < n; i ++)
        {
            int counter = output.size();
            while(counter)
            {
                int val = output[counter - 1];
                val += 1<<offset;
                output.push_back(val);
                counter --;
            }
            
            offset ++;
        }
        
        return output;
    }
};