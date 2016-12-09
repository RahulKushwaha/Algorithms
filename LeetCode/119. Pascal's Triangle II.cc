class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output;
        if(rowIndex < 0)
        {
            return output;
        }
        
        output.resize(rowIndex + 1);
        output[0] = 1;
        
        for(int i = 1; i <= rowIndex; i ++)
        {
            int last = output[0];
            int limit = i + 1;
            for(int j = 1; j <= limit / 2; j ++)
            {
                int temp = output[j];
                output[j] = output[j] + last; 
                last = temp;
            }
            
            int a = 0, b = limit - 1;
            while(a < b)
            {
                output[b] = output[a];
                b--; 
                a++;
            }
        }
        
        return output;
    }
};