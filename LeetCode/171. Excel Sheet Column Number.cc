class Solution {
public:
    int titleToNumber(string s) {
        int num = 0; 
        for(int i = s.size() - 1, j = 1; i >= 0; i --, j *= 26)
        {
            int temp = (s[i] - 'A' + 1) * j;
            num += temp;   
        }
        
        return num;
    }
};