class Solution {
public:
    string generateString(string& word, int number, int length)
    {
        int counter = 0;
        int index = length - 1;
        stringstream stringWriter;
        while(length)
        {
            if(number & 1)
            {
                counter ++;
            }
            else
            {
                if(counter > 0)
                {
                    string temp = to_string(counter);
                    reverse(temp.begin(), temp.end());
                    stringWriter<<temp;
                }
                
                if(index >= 0)
                {
                    stringWriter<<word[index];
                }
                
                counter = 0;
            }
            
            index -- ;
            length -- ;
            number /= 2;
        }
        
        if(counter > 0)
        {
            string temp = to_string(counter);
            reverse(temp.begin(), temp.end());
            stringWriter<<temp;
        }
        
        return stringWriter.str();
    }
    
    vector<string> generateAbbreviations(string word) {
        int length = word.size();
        vector<string> output;
        
        if(length == 0)
        {
            output.push_back(word);
            return output;
        }
        
        int limit = 1<<length;
        for(int i = 0; i < limit; i ++)
        {
            string temp = generateString(word, i, length);
            reverse(temp.begin(), temp.end());
            output.push_back(temp);
        }
        
        return output;
    }
};