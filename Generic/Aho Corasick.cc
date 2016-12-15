struct Trie {
    unordered_map<char, Trie*> next;
    bool isLeaf;
    string word;
    Trie* failure;

    Trie(bool leafNode, string& str) : isLeaf(leafNode), word(str), failure(NULL) {}
    Trie(bool leafNode) : isLeaf(leafNode), failure(NULL) {}

    bool add(string& word) {
        int length = word.size();

        if (length == 0) {
            return false;
        }

        Trie* currentNode = this;
        for (int i = 0; i < length; i++) {
            unordered_map<char, Trie*>::iterator itr = currentNode->next.find(word[i]);
            if (itr != currentNode->next.end()) {
                currentNode = itr->second;
            }
            else {
                Trie* newNode = new Trie(false);
                currentNode->next[word[i]] = newNode;
                currentNode = newNode;
            }
        }

        currentNode->isLeaf = true;
        currentNode->word = word;

        return true;
    }

    void buildFailure() {
        queue<Trie*> nodes;

        for (unordered_map<char, Trie*>::iterator itr = this->next.begin(); itr != this->next.end(); itr++) {
            itr->second->failure = this;
            nodes.push(itr->second);
        }

        while (nodes.empty() == false) {
            Trie* top = nodes.front();
            nodes.pop();

            for (unordered_map<char, Trie*>::iterator itr = top->next.begin(); itr != top->next.end(); itr++) {
                Trie* failureNode = top->failure;

                while (failureNode) {
                    unordered_map<char, Trie*>::iterator nextItr = failureNode->next.find(itr->first);
                    if (nextItr != failureNode->next.end()) {
                        itr->second->failure = nextItr->second;
                        break;
                    }
                    else {
                        failureNode = failureNode->failure;
                    }
                }

                if (failureNode == NULL) {
                    itr->second->failure = this;
                }

                nodes.push(itr->second);
            }
        }
    }

    vector<string> search(string str) {
        Trie* currentNode = this, *root = this;
        int length = str.size();
        vector<string> output;

        for (int i = 0; i <= length; ) {
            if (currentNode->isLeaf) {
                output.push_back(currentNode->word);
            }

            if (i == length) { 
                break;
            }

            unordered_map<char, Trie*>::iterator itr = currentNode->next.find(str[i]);

            if (itr != currentNode->next.end()) {
                currentNode = itr->second;
                i++;
            }
            else if (currentNode == root) {
                i++;
            }
            else {
                currentNode = currentNode->failure;
            }
        }

        return output;
    }
};