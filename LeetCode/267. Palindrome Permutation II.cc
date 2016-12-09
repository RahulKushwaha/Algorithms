// This can also be solved by generating all distinct permutations using DFS.
class Solution {
public:
    bool isPalindromePossible(char * freq)
    {
        int oddCount = 0;
        for(int i = 0; i < 256; i ++)
        {
            if(freq[i] % 2 != 0)
            {
                oddCount ++;
            }
        }
        
        return oddCount < 2;
    }
    
    string reverseCopy(string str)
    {
        string t;
        for (std::string::reverse_iterator rit=str.rbegin(); rit!=str.rend(); ++rit)
        {
            t += *rit;
        }
        
        return t;
    }
    
    void reverse(string& s, int l , int h)
    {
        while(l < h)
        {
            swap(s[l], s[h]);
            l ++;
            h --;
        }
    }
    
    vector<string> generatePalindromes(string s) {
        vector<string> output;
        
        if(s.size() == 1)
        {
            output.push_back(s);
            return output;
        }
        
        char freq[256] = {0};
        
        for(int i = 0; i < s.size(); i ++)
        {
            freq[s[i]]++;
        }
        
        if(isPalindromePossible(freq) == false)
        {
            return output;
        }
        
        string text;
        char endCh;
        bool hasEndCh = false;
        for(int i = 0; i < 256; i ++)
        {
            if(freq[i])
            {
                for(int j = 0; j < freq[i]/2; j ++)
                {
                    text += (char)i;
                }
                
                if(freq[i] % 2 != 0)
                {
                    hasEndCh = true;
                    endCh = (char)i;
                }
            }
        }
        
        string ans = text;
        if(hasEndCh)
        {
            ans += endCh;
        }
        
        ans += reverseCopy(text);
        output.push_back(ans);

        int length = text.size();
        int increasingSeqIndex = length - 1;
        while(true)
        {
            increasingSeqIndex = length - 1;
            for(int i = length - 1; i >= 0; i --)
            {
                if(text[i] >= text[increasingSeqIndex])
                {
                    increasingSeqIndex = i;
                    continue;
                }
                
                break;
            }

            if(increasingSeqIndex == 0)
            {
                break;
            }

            int pivot = increasingSeqIndex - 1; 
            int swapIndex = length - 1;
            
            for(int i = length - 1; i >= 0; i --)
            {
                if(text[i] > text[pivot])
                {
                    swapIndex = i;
                    break;
                }
            }
            
            swap(text[pivot], text[swapIndex]);
            
            reverse(text, increasingSeqIndex, length - 1);
            
            string ans = text;
            if(hasEndCh)
            {
                ans += endCh;
            }
            
            ans += reverseCopy(text);
            
            output.push_back(ans);
        }
        
        return output;
    }
};