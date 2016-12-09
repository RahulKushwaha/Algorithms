class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int freqRansom[26] = {0};
        int freqMag[26] = {0};
        
        for(int i = ransomNote.size(); i >= 0; i --)
        {
            freqRansom[ransomNote[i] - 'a'] ++;
        }
        
        for(int i = magazine.size(); i >= 0; i --)
        {
            freqMag[magazine[i] - 'a'] ++;
        }
        
        for(int i = 0; i < 26; i ++)
        {
            if(freqRansom[i] > freqMag[i])
            {
                return false;
            }
        }
        
        return true;
        
    }
};