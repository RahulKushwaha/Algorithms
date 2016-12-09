class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> output;
        
        for(int i = 0; i < 12; i ++)
        {
            for(int j = 0; j < 60; j ++)
            {
                bitset<4> hourBits(i);
                bitset<6> minuteBits(j);
                
                if(hourBits.count() + minuteBits.count() == num)
                {
                    output.push_back(to_string(i) + ":" + (j < 10 ? "0" : "") + to_string(j));   
                }
            }
        }
        
        return output;
    }
};