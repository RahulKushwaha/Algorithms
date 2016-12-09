class Solution {
public:
    void reverseWords(string &s) {
        int length = s.size();
        
        int i = 0; 
        int j = length - 1;
        
        while(i < j)
        {
            char ch = s[i];
            s[i] = s[j];
            s[j] = ch;
            i ++; 
            j --;
        }
        
        for(i = 0, j = 0; i < length && j < length;)
        {
            while(i < length && s[i] != ' ')
            {
                i ++;
            }
            
            int a = i - 1, b = j;
            while(b < a)
            {
                char ch = s[a];
                s[a] = s[b];
                s[b] = ch;
                a --; 
                b ++;
            }
            
            i ++;
            j = i;
        }
    }
};