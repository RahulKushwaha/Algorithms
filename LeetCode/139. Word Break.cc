struct Trie 
{
    unordered_map<char, Trie*> next;
    string word;
    bool isLeaf;
};

class Solution {
public:
    Trie root;
    unordered_set<int> lookup;
    void Add(string& s)
    {
        if(s.size() == 0)
        {
            return;
        }
        
        Trie* currentNode = &root;
        for(int i = 0; i < s.size(); i ++)
        {
            unordered_map<char, Trie*>::iterator itr = currentNode->next.find(s[i]);
            if(itr != currentNode->next.end())
            {
                currentNode = itr->second;
            }
            else
            {
                Trie* newNode = new Trie();
                newNode->isLeaf = false;
                currentNode->next[s[i]] = newNode;
                
                currentNode = newNode;
            }
        }
        
        currentNode->word = s;
        currentNode->isLeaf = true;
    }
    
    bool search(string& s, int index)
    {
        if(s.size() == index)
        {
            return true;    
        }
        
        if(lookup.find(index) != lookup.end())
        {
            return false;
        }
        
        Trie* currentNode = &root;
        
        for(int i = index; i < s.size(); i ++)
        {
            unordered_map<char, Trie*>::iterator itr = currentNode->next.find(s[i]);
            if(itr == currentNode->next.end())
            {
                return false;
            }
            else
            {
                currentNode = itr->second;
                if(currentNode->isLeaf)
                {
                    if(search(s, i + 1))
                    {
                        return true;
                    }
                    else
                    {
                        lookup.insert(i + 1);
                    }
                }
            }
        }
        
        return false;
    }
    
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        for(unordered_set<string>::iterator itr = wordDict.begin(); itr != wordDict.end(); itr ++)
        {
            string t= *itr;
            Add(t);
        }
        
        if(s.size() == 0)
        {
            return false;
        }
        
        return search(s, 0);
    }
};