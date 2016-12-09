class WordDistance {
public:
    unordered_map<string, vector<int>> lookup;
    WordDistance(vector<string>& words) {
        int length = words.size();
        for(int i = 0; i < length; i ++)
        {
            lookup[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int>& word1Indices = lookup.find(word1)->second;
        vector<int>& word2Indices = lookup.find(word2)->second;
        int diff = INT_MAX;
        
        for(vector<int>::iterator itr1 = word1Indices.begin(), itr2 = word2Indices.begin(); 
            itr1 != word1Indices.end() && itr2 != word2Indices.end();)
            {
                diff = min(abs(*itr1 - *itr2), diff);
                if(*itr1 < *itr2)
                {
                    itr1++;
                }
                else
                {
                    itr2++;
                }
            }
            
            return diff;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");