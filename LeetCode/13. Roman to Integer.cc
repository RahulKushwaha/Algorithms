map<char, int> lookup {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
map<char, char> substractors {{'M', 'C'}, {'D', 'C'}, {'C', 'X'}, {'L', 'X'}, {'V', 'I'}, {'X', 'I'}};

class Solution {
public:

    int romanToInt(string s) {
        int length = s.size(), output = 0;

        for(int i = 0; i < s.size(); i ++)
        {
            output += lookup[s[i]];
            map<char, char>::iterator itr = substractors.find(s[i]);
            if(itr != substractors.end())
            {
                if(itr->second == s[i - 1])
                {
                    output -= lookup[s[i - 1]] * 2;
                }
            }
        }
        
        return output;
    }
};