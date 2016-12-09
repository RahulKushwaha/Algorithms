struct Trie{
    unordered_map<char, Trie*> next;
    vector<string> words;
};

class Solution {
public:

    void add(string& word)
    {
        int length = word.size();
        if(length == 0)
        {
            return;
        }
        
        Trie* currentNode = &root;
        for(int i = 0; i < length; i ++)
        {
            currentNode->words.push_back(word);
            unordered_map<char, Trie*>::iterator itr = currentNode->next.find(word[i]);
            if(itr == currentNode->next.end())
            {
                Trie* newNode = new Trie();
                currentNode->next[word[i]] = newNode;
                currentNode = newNode;
            }
            else
            {
                currentNode = itr->second;
            }
        }
    }
    
    Trie root;
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        int length = words.size();
        vector<vector<string>> output;
        if(length == 0)
        {
            return output;
        }
        
        vector<string> currentOutput;
        int squareSize = words[0].size();
        
        for(int i = 0; i < length; i ++)
        {
            add(words[i]);
        }
        
        for(int i = 0; i < length; i ++)
        {
            currentOutput.push_back(words[i]);
            wordSquares(words, 1, length, squareSize, currentOutput, output);
            currentOutput.pop_back();
        }
        
        return output;
    }

    string getPrefix(vector<string>& words, int index)
    {
        stringstream sStream;
        for(int i = 0; i < index; i ++)
        {
            sStream<<words[i][index];
        }
        
        return sStream.str();
    }
    
    vector<string> getWords(string& prefix)
    {
        vector<string> words;
        Trie* currentNode = &root;
        int length = prefix.size();
        
        for(int i = 0; i < length; i ++)
        {
            unordered_map<char, Trie*>::iterator itr = currentNode->next.find(prefix[i]);
            if(itr == currentNode->next.end())
            {
                return words;
            }
            
            currentNode = itr->second;
        }
        
        if(currentNode)
        {
            return currentNode->words;
        }
        
        return words;
    }
    
    void wordSquares(vector<string>& words,
                     int index,
                     int length,
                     int squareSize,
                     vector<string>& currentOutput,
                     vector<vector<string>>& output)
    {
        if(index >= squareSize)
        {
            output.push_back(currentOutput);
            return;
        }
        
        string prefix = getPrefix(currentOutput, index);
        
        vector<string> nextWords = getWords(prefix);
        int nextWordsCount = nextWords.size();
        //cout<<nextWordsCount<<endl;

        for(int i = 0; i < nextWordsCount; i ++)
        {
            //cout<<words[i]<<endl;
            currentOutput.push_back(nextWords[i]);
            wordSquares(words, index + 1, length, squareSize, currentOutput, output);
            currentOutput.pop_back();
        }
    }
};