class Solution {

public:

void reverseWords(string &s) {
        
        int index = s.find_first_not_of(' ');
        if (index != std::string::npos)
            s = s.substr(index);
        
        index = s.find_last_not_of(' ');
        if (index !=std::string::npos)
            s = s.substr(0, index + 1);
        
        bool first = true;
        string text;
        for(int i = 0; i < s.size(); i ++)
        {
            if(s[i] == ' ')
            {
                if(first)
                {
                    text += s[i];
                    first = false;
                }
            }
            else
            {
                first = true;
                text += s[i];
            }
        }
        
        s = text;
        
        if(s.size() == 1)
        {
            if(s[0] == ' ')
            {
                return s.clear();
            }
        }
        
        int i = 0, j = s.size() - 1;

        while(i < j)
        {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;

            i++;
            j--;
        }

        for(int i = 0, j = 0; i < s.size() && j < s.size(); )
        {
            while(s[i] == ' ' && i < s.size())
            {
                i++;
                j++;
            }

            while(s[j] != ' ' && j < s.size())
            {
                j++;
            }

            int a = i, b = j - 1;
            while(a < b)
            {
                char temp = s[a];
                s[a] = s[b];
                s[b] = temp;

                a++;
                b--;
            }

            j++;
            i = j;
        }
    }
};