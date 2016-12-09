class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int length = words.size();
        
        if(length == 0)
        {
            return  0;
        }
        
        int index1 = -1;
        int index2 = -1;
        int diff = INT_MAX;
        
        for(int i = 0; i < words.size(); i ++)
        {
            string & word = words[i];
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
                diff = min(abs(index1 - index2), diff); 
            }
        }
        
        return diff == INT_MAX? -1 : diff;
    }
};