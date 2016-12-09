class Solution {
public:
    bool isPalindrome(string& s)
    {
        int i = 0;
        int j = s.size() - 1;
        while(i < j)
        {
            if(s[i] != s[j])
            {
                return false;
            }
            
            i ++;
            j --;
        }
        
        return true;
    }
    
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int length = words.size();
        
        unordered_map<string, int> lookup;
        vector<vector<int>> output;
        
        for(int i = 0; i < length; i ++)
        {
            lookup[words[i]] = i;
        }
        
        for(int i = 0; i < length; i ++)
        {
            string& currentWord = words[i];
            reverse(words[i].begin(), words[i].end());
            int wordLength = currentWord.size();
            
            for(int j = 0; j <= wordLength; j ++)
            {
                string left = currentWord.substr(0, j);
                string right = currentWord.substr(j);
                
                unordered_map<string, int>::iterator itr = lookup.find(left);
                if(itr != lookup.end() && isPalindrome(right) && i != itr->second && wordLength > j)
                {
                    output.push_back(vector<int>{itr->second, i});
                }
                
                itr = lookup.find(right);
                if(itr != lookup.end() && isPalindrome(left) && i != itr->second)
                {
                    output.push_back(vector<int>{i, itr->second});
                }
            }
        }
        
        return output;
    }
};