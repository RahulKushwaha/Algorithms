class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isLeaf = false;
    }
    
    bool isLeaf; 
    map<char, TrieNode*> next;
};

class Trie {
public:
    Trie() {
    }

    // Inserts a word into the trie.
    void insert(string word) {
               
        if(word.size() == 0)
        {
            return;
        }
        
        TrieNode* currentNode = &root;
        for(int i = 0; i < word.size(); i ++)
        {
            map<char, TrieNode*>::iterator nextNode = currentNode->next.find(word[i]);
            if(nextNode != currentNode->next.end())
            {
                currentNode = nextNode->second;
            }
            else
            {
                TrieNode * newNode = new TrieNode();
                
                currentNode->next.insert(pair<char, TrieNode*>(word[i], newNode));
                
                currentNode = newNode;
            }
        }
        
        currentNode->isLeaf = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        if(word.size() == 0)
        {
            return false;
        }
        
        TrieNode* currentNode = &root;
        for(int i = 0; i < word.size(); i ++)
        {
            map<char, TrieNode*>::iterator itr = currentNode->next.find(word[i]);
            if(itr != currentNode->next.end())
            {
                currentNode = itr->second;
            }
            else
            {
                return false;
            }
        }
        
        return currentNode->isLeaf;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        if(prefix.size() == 0)
        {
            return false;
        }
        
        TrieNode* currentNode = &root;
        for(int i = 0; i < prefix.size(); i ++)
        {
            map<char, TrieNode*>::iterator itr = currentNode->next.find(prefix[i]);
            if(itr != currentNode->next.end())
            {
                currentNode = itr->second;
            }
            else
            {
                return false;
            }
        }
        
        return true;
    }

private:
    TrieNode root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");