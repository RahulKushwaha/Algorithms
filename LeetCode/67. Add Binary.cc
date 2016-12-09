class Solution {
public:
    string addBinary(string a, string b) {
        string output;
        
        int i = a.size() - 1, j = b.size() - 1;
        int c = 0;
        while(i >= 0 || j >= 0 || c)
        {
            c += i >= 0 ? a[i --] - '0' : 0;
            c += j >= 0 ? b[j --] - '0' : 0;
            output = (c % 2 ? '1' : '0') + output;
            c /= 2;
        }
        
        return output;
    }
};