using namespace std;

struct Trie
{
    map<char, Trie*> next;
    bool isLeaf;
};

class WordDictionary {
public:
    
    WordDictionary()
    {
        root.isLeaf = false;
    }
    
    Trie root;
    // Adds a word into the data structure.
    void addWord(string word) {
        
        if(word.size() == 0)
        {
            return;
        }
        
        Trie* currentNode = &root;
        for(int i = 0; i < word.size(); i ++)
        {
            map<char, Trie*>::iterator nextNode = currentNode->next.find(word[i]);
            if(nextNode != currentNode->next.end())
            {
                currentNode = nextNode->second;
            }
            else
            {
                Trie * newNode = new Trie();
                newNode->isLeaf = false;
                
                currentNode->next.insert(pair<char, Trie*>(word[i], newNode));
                
                currentNode = newNode;
            }
        }
        
        currentNode->isLeaf = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.size() == 0)
        {
            return false;
        }
        
        return search(word, 0, &root);
    }
    
    bool search(string &word, int counter, Trie * node)
    {
        if(node != NULL && word.size() == counter && node->isLeaf)
        {
            return true;
        }
        
        if(counter < word.size())
        {
            if(word[counter] == '.')
            {
                for(map<char, Trie*>::iterator itr = node->next.begin(); itr != node->next.end(); itr ++)
                {
                    if(search(word, counter + 1, itr->second))
                    {
                        return true;
                    }
                }
            }
            else
            {
                map<char, Trie*>::iterator nextNode = node->next.find(word[counter]);
                if(nextNode != node->next.end())
                {
                    return search(word, counter + 1, nextNode->second);
                }
            }
        }
        
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");