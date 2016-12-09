struct Trie
{
    map<char, Trie*> next;
    bool isLeaf;
    string word;
};

class Solution {
public:
    Trie root;
    
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
            map<char, Trie*>::iterator itr = currentNode->next.find(word[i]);
            if(itr == currentNode->next.end())
            {
                Trie* newNode = new Trie();
                newNode->isLeaf = false;
                
                currentNode->next[word[i]] = newNode;
                
                currentNode = newNode;
            }
            else
            {
                currentNode = itr->second;
            }
        }
        
        currentNode->isLeaf = true;
        currentNode->word = word;
    }
    
    void search(vector<vector<char>>& board, vector<string>& output)
    {
        int rows = board.size();
        if(rows == 0)
        {
            return;
        }
        
        int cols = board[rows - 1].size();
        
        bool ** visited = new bool*[rows];
        for(int i = 0 ; i < rows; i ++)
        {
            visited[i] = new bool[cols];
            for(int j = 0; j < cols; j ++)
            {
                visited[i][j] = false;
            }
        }
        
        unordered_set<string> words;
        
        for(int i = 0; i < rows; i ++)
        {
            for(int j = 0; j < cols; j ++)
            {
                search(board, &root, i, j, rows, cols, visited, words);
            }
        }
        
        for(unordered_set<string>::iterator itr = words.begin(); itr != words.end(); itr ++)
        {
            output.push_back(*itr);
        }
    }
    
    bool search(vector<vector<char>>& board,
                Trie* currentNode,
                int x,
                int y,
                int rows, 
                int cols,
                bool ** visited,
                unordered_set<string>& output)
    {
        if(currentNode == NULL)
        {
            return false;
        }

        map<char, Trie*>::iterator itr = currentNode->next.find(board[x][y]);
        if(itr == currentNode->next.end())
        {
            return false;
        }
        else if(itr->second->isLeaf)
        {
            output.insert(itr->second->word);
        }
        
        visited[x][y] = true;
        
        bool result = false;
        if(x + 1 < rows)
        {
            if(visited[x + 1][y] == false)
            {
                result |= search(board, itr->second, x + 1, y, rows, cols, visited, output);
            }
        }
        
        if(x - 1 >= 0)
        {
            if(visited[x - 1][y] == false)
            {
                result |= search(board, itr->second, x - 1, y, rows, cols, visited, output);
            }
        }
        
        if(y + 1 < cols)
        {
            if(visited[x][y + 1] == false)
            {
                result |= search(board, itr->second, x, y + 1, rows, cols, visited, output);
            }
        }
        
        if(y - 1 >= 0)
        {
            if(visited[x][y - 1] == false)
            {
                result |= search(board, itr->second, x, y - 1, rows, cols, visited, output);
            }
        }
        
        visited[x][y] = false;
        
        return result;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int length = words.size();
        vector<string> output;
        if(length == 0)
        {
            return output;
        }
        
        for(int i = 0; i < length; i ++)
        {
            add(words[i]);
        }
        
        search(board, output);
        
        return output;
    }
};