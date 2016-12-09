class Solution {
public:
    typedef long long LL;
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> output;
        int length = s.size();
        if(length < 10)
        {
            return output;
        }
        
        LL hash = 0;
        LL b = 1;
        LL mul = 19;
        unordered_map<LL, string> lookup;
        
        for(int i = 0; i < 10; i ++)
        {
            hash *= mul;
            hash += s[i];
            b *= mul;
        }
        
        lookup.insert(pair<LL, string>(hash, s.substr(0, 10)));
        unordered_set<int> dups;
        for(int i = 10; i < length; i ++)
        {
            hash *= mul;
            hash += s[i];
            hash -= b * s[i - 10];
            
            unordered_map<LL, string>::iterator itr = lookup.find(hash);
            
            if(itr == lookup.end())
            {
                lookup.insert(pair<LL, string>(hash, s.substr(i - 9, 10)));
            }
            else
            {
                if(dups.find(hash) == dups.end())
                {
                    output.push_back(s.substr(i - 9, 10));
                    dups.insert(hash);
                }
            }
        }

        return output;
    }
};