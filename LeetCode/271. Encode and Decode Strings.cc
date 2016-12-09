class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int length = strs.size();
        stringstream output;
        for(int i = 0; i < length; i ++)
        {
            string& str = strs[i];
            int stringLength = str.size(); 
            
            for(int j = 0; j < stringLength; j ++)
            {
                if(str[j] == '%')
                {
                    output<< "%%";
                }
                else
                {
                    output << str[j];
                }
            }
            
            output << "%E";
        }
        
        return output.str();
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        int length = s.size();
        vector<string> output;
        if(length == 0)
        {
            return output;
        }
        
        string line;
        bool escape = false;
        for(int i = 0; i < length; i ++)
        {
            if(escape == false)
            {
                if(s[i] == '%')
                {
                    escape = true;
                }
                else
                {
                    line += s[i];
                }
            }
            else
            {
                if(s[i] == 'E')
                {
                    output.push_back(line);
                    line = "";
                }
                else
                {
                    line += "%";
                }
                escape = false;
            }
        }
        
        return output;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));