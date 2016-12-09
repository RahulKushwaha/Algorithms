class Solution {
public:
    string countAndSay(int n) {
        string output = "1";
        if(n == 0)
        {
            return output;
        }
        
        for(int i = 0; i < n - 1; i ++)
        {
            int count = 1;
            stringstream temp;
            int length = output.size();
            for(int j = 1; j < length; j ++)
            {
                if(output[j] == output[j - 1])
                {
                    count ++;
                }
                else
                {
                    temp <<to_string(count)<<output[j - 1]; 
                    count = 1;
                }
            }
            
            temp << to_string(count) << output[length - 1];
            output = temp.str();
        }
        
        return output;
    }
};