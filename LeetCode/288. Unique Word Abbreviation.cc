class ValidWordAbbr {
public:
    string getAbv(string str)
    {
        int length = str.size();
        string abv;
        if(length <= 2)
        {
            abv = str;
        }
        else
        {
            abv = str[0] + to_string(length - 2) + str[length - 1];
        }
        
        return abv;
    }
    
    unordered_map<string, int> lookup;
    unordered_set<string> words;
    
    ValidWordAbbr(vector<string> &dictionary) {
        int length = dictionary.size();
        for(int i = 0; i < length; i ++)
        {
            words.insert(dictionary[i]);
            string abv = getAbv(dictionary[i]);
            int wordSize = dictionary[i].size();
            
            unordered_map<string, int>::iterator itr = lookup.find(abv);
            if(itr == lookup.end())
            {
                lookup.insert(pair<string, int>(abv, 1));
            }
            else
            {   
                if(wordSize > 2)
                {
                    itr->second ++;
                }
            }
        }
    }

    bool isUnique(string word) {
        string abv = getAbv(word);
        unordered_map<string, int>::iterator itr = lookup.find(abv);
        if(itr == lookup.end())
        {
            return true;
        }
        
        unordered_set<string>::iterator i = words.find(word);
        
        if(i == words.end())
        {
            return false;    
        }
        
        return itr->second == 1;
    }
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");