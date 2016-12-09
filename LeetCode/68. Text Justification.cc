class Solution {
public:
    string getLastLine(vector<string> &words, int wordsLength, int maxWidth)
    {
        stringstream output;
        int remainingSpaces = maxWidth - wordsLength; 
        for(int i = 0; i < words.size() - 1; i ++)
        {
            output<< words[i]<< " ";
            remainingSpaces --;
        }
        
        output << words[words.size() - 1];
        
        for(int i = 0; i < remainingSpaces; i ++)
        {
            output << " ";
        }
        
        return output.str();
    }
    
    string getLine(vector<string>& words, int wordsLength, int maxWidth)
    {
        stringstream output;
        int totalWords = words.size();
        int totalSpace = maxWidth - wordsLength;
        
        string spaceChunk = string(totalSpace, ' ');
        int remaining = 0;
        
        if(totalWords != 1)
        {
            spaceChunk = string(totalSpace / (totalWords - 1), ' ');
            remaining = totalSpace % (totalWords - 1);
        }
        
        for(int i = 0; i < totalWords - 1; i ++)
        {
            output<<words[i]<<spaceChunk;
            if(remaining)
            {
                output<<" ";
                remaining --;
            }
        }
        
        output<<words[totalWords - 1];
        
        if(totalWords == 1)
        {
            output<<spaceChunk;
        }
        
        return output.str();
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int size = words.size();
        
        int lineLength = 0;
        int lineWordsLength = 0;
        vector<string> lineWords; 
        vector<string> output;
        
        for(int i = 0; ;)
        {
            int currentWordSize = i == size? INT_MAX : words[i].size();
            if(currentWordSize <= maxWidth - lineLength)
            {
                lineWords.push_back(words[i]);
                lineLength += currentWordSize + 1;
                lineWordsLength += currentWordSize;
                i ++;
            }
            else
            {
                if(i == size)
                {
                    string line = getLastLine(lineWords, lineWordsLength, maxWidth);
                    output.push_back(line);
                    break;
                }
                
                string line = getLine(lineWords, lineWordsLength, maxWidth);

                output.push_back(line);
                lineWords.clear();
                lineLength = 0;
                lineWordsLength = 0;
            }
        }
        
        return output;
    }
};