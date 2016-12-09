class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int length = nums.size();
        string output;
        if(length == 0)
        {
            return output;
        }
        
        vector<string> items;
        for(int i = 0; i < length; i ++)
        {
            items.push_back(to_string(nums[i]));
        }
        
        sort(items.begin(), items.end(), compare);
        stringstream strStream;
        for(int i = length - 1; i >= 0; i --)
        {
            strStream<<items[i];
        }
        
        output = strStream.str();
        if(output[0] != '0')
        {
            return output;
        }
        
        return "0";
    }
    
    bool static compare(string& a, string& b)
    {
        return a + b < b + a;
    }
};


