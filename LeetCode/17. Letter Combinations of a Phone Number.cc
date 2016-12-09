class Solution {
public:
    unordered_map<int, vector<char>> lookup;
    
    void init()
    {
        vector<char> chars;
        chars.push_back('a');
        chars.push_back('b');
        chars.push_back('c');
        lookup[2] = chars;
        
        chars.clear();
        chars.push_back('d');
        chars.push_back('e');
        chars.push_back('f');
        lookup[3] = chars;
        
        chars.clear();
        chars.push_back('g');
        chars.push_back('h');
        chars.push_back('i');
        lookup[4] = chars;
        
        chars.clear();
        chars.push_back('j');
        chars.push_back('k');
        chars.push_back('l');
        lookup[5] = chars;
        
        chars.clear();
        chars.push_back('m');
        chars.push_back('n');
        chars.push_back('o');
        lookup[6] = chars;
        
        chars.clear();
        chars.push_back('p');
        chars.push_back('q');
        chars.push_back('r');
        chars.push_back('s');
        lookup[7] = chars;
        
        chars.clear();
        chars.push_back('t');
        chars.push_back('u');
        chars.push_back('v');
        lookup[8] = chars;
        
        chars.clear();
        chars.push_back('w');
        chars.push_back('x');
        chars.push_back('y');
        chars.push_back('z');
        lookup[9] = chars;
    }
    
    vector<string> letterCombinations(string digits) {
        int length = digits.size();
        vector<string> output;
        if(length == 0)
        {
            return output;
        }
        
        init();
        letterCombinations(digits, 0, length, "", output);
        
        return output;
    }
    
    void letterCombinations(string& digits,
                            int index,
                            int length,
                            string current,
                            vector<string>& output)
    {
        if(current.size() == length)
        {
            output.push_back(current);
            return;
        }
        
        vector<char>& chars = lookup[digits[index] - '0'];
        int limit = chars.size();
        for(int j = 0; j < limit; j ++)
        {
            letterCombinations(digits, index + 1, length, current + chars[j], output);
        }
    }
};