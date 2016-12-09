class Solution {
public:
    int lengthLongestPath(string input) {
        int length = input.size();
        int i = 0, wordLength = 0, totalLength = 0, output = 0, current = 0;
        list<int> partitions;
        
        while(i < length)
        {
            if(input[i] == '\n')
            {
                current = 0;
                for(i = i + 1; i < length && (input[i] == '\t' || input[i] == '\n'); i ++)
                {
                    current ++;
                }
                
                while(partitions.size() > current)
                {
                    totalLength -= partitions.back();
                    partitions.pop_back();
                }
                
                wordLength = 0;
            }
            else
            {
                bool file = false;
                while(i < length && input[i] != '\n')
                {
                    wordLength ++;
                    i ++;
                    if(input[i] == '.')
                    {
                        file = true;
                    }
                }
                
                partitions.push_back(wordLength);
                totalLength += wordLength;
                int pathLength = totalLength + partitions.size() - 1;
                if(file)
                {
                    output = max(output, pathLength);
                }
            }
        }
        
        return output;
    }
};