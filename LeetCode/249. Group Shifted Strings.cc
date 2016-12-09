class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int length = strings.size();
        
        vector<vector<string>> output;
        
        if(length == 0)
        {
            return output;
        }
        
        unordered_map<string, vector<string>> lookup;
        
        for(int i = 0; i < length; i ++)
        {
            string& word = strings[i];
            int limit = word.size();
            char minCh = word[0];
            
            string key = word;
            for(int j = 0; j < limit; j ++)
            {
                if(key[j] - minCh < 0)
                {
                    key[j] = key[j] - minCh + 26 + 'a';
                }
                else
                {
                    key[j] = key[j] - minCh + 'a';    
                }
            }
            
            unordered_map<string, vector<string>>::iterator itr = lookup.find(key);
            if(itr == lookup.end())
            {
                vector<string> variants;
                variants.push_back(word);
                
                lookup.insert(pair<string, vector<string>>(key, variants));
            }
            else
            {
                lookup[key].push_back(word);
            }
        }
        
        for(unordered_map<string, vector<string>>::iterator itr = lookup.begin(); itr != lookup.end(); itr ++)
        {
            output.push_back(itr->second);
        }
        
        return output;
    }
};