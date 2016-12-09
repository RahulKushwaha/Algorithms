class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int length = words.size();
        int index1 = INT_MAX;
        int diff = INT_MAX;
        
        if(word1.compare(word2) == 0)
        {
            for(int i = 0; i < length; i ++)
            {
                if(word1.compare(words[i]) == 0)
                {
                    diff = min(diff, abs(i - index1));
                    index1 = i;
                }
            }
            
            return diff;
        }
        
        index1 = -1;
        int index2 = -1;
        
        for(int i = 0; i < length; i ++)
        {
            string &word = words[i];
            
            if(word.compare(word1) == 0)
            {
                index1 = i;
            }
            else if(word.compare(word2) == 0)
            {
                index2 = i;
            }
            
            if(index1 != -1 && index2 != -1)
            {
                diff = min(abs(index2 - index1), diff);
            }
        }
        
        return diff;
    }
};