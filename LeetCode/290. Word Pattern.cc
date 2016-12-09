class Solution {
public:
    string getNextWord(string &str)
    {
        string output;
        int totalLength = str.size();
        if(totalLength == 0)
        {
            return output;
        }
        
        int index = 0;
        int startIndex = 0;
        if(str[index] == ' ')
        {
            startIndex++;
            index ++;
        }
        
        while(index < totalLength)
        {
            if(str[index] != ' ')
            {
                index ++;
            }
            else
            {
                break;
            }
        }
        
        output = str.substr(startIndex, index - startIndex);
        str = str.substr(index);
        return output;
    }
    
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> lookup;
        unordered_set<string> words;
        int i = 0;
        for(; i < pattern.size(); i ++)
        {
            string word = getNextWord(str);
            
            if(word.size() == 0)
            {
                return false;
            }
            
            unordered_map<char, string>::iterator itr = lookup.find(pattern[i]);
            if(itr == lookup.end())
            {
                lookup.insert(pair<char, string>(pattern[i], word));
                // Check if the same mapping word has already been added for some other domain word.
                pair<unordered_set<string>::iterator, bool> result = words.insert(word);
                if(result.second == false)
                {
                    return false;
                }
            }
            else
            {
                if(itr->second.compare(word) != 0)
                {
                    return false;
                }
            }
        }
        
        if(str.size() != 0)
        {
            return false;
        }
        
        return true;
    }
};