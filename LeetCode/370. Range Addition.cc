class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> output;
        
        if(length < 1)
        {
            return output;
        }
        
        output.resize(length, 0);
        
        for(vector<vector<int>>::iterator itr = updates.begin(); itr != updates.end(); itr ++)
        {
            vector<int>& update = (*itr);
            if(update[0] >= 0)
            {
                output[update[0]] += update[2];
            }
            
            if(update[1] + 1 < length)
            {
                output[update[1] + 1] += (-1 * update[2]); 
            }
        }
        
        for(int i = 1; i < length; i ++)
        {
            output[i] += output[i - 1];
        }
        
        return output;
    }
};