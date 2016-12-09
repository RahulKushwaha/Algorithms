class Solution {
public:
    string reverseVowels(string s) {
        
        if(s.size() == 0)
        {
            return s;
        }
        
        unordered_set<char> vowels;
        vowels.insert('a');
        vowels.insert('e');
        vowels.insert('i');
        vowels.insert('o');
        vowels.insert('u');
        
        int i = 0, j = s.size() - 1;
        
        while(i < j)
        {
            if(vowels.find(tolower(s[i])) == vowels.end())
            {
                i ++ ;
                continue;
            }
            
            if(vowels.find(tolower(s[j])) == vowels.end())
            {
                j -- ;
                continue;
            }
            
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            
            i ++;
            j --;
        }
        
        return s;
    }
};