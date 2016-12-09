class Solution {
public:
void reverseString(string & s)
{
    int i = 0, j = s.size() - 1;
    while(i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i ++;
        j --;
    }
}

void failure(vector<int> & f, string & s)
{
    f.resize(s.size());
    f[0] = 0;
    int j = 0;
    for(int i = 1; i < s.size(); i ++)
    {
        while(j > 0 && s[i] != s[j])
        {
            j = f[j - 1];
        }

        if(s[j] == s[i])
        {
            j ++;
        }

        f[i] = j;
    }
}

int search(string &s, string & p, vector<int>& f)
{
    int i = 0; // the initial state of the automaton is the empty string.
    int j = 0; // The first character of the text.
    for(;; )
    {
        cout<<i<<" "<<j<<endl;
        // We reached the end of the string.
        if (j == s.size())
        {
            break;
        }

        if(s[j] == p[i])
        {
            i ++;
            j ++;
        }

        else if (i > 0)
        {
            i = f[i - 1];
        }
        else
        {
            j ++;
        }
    }

    return i;
}

string shortestPalindrome(string& s)
{
    if(s.size() == 0)
    {
        return s;
    }
    string r = s;
    reverseString(r);

    vector<int> f;
    failure(f, s);

    int index = search(r, s, f);
    cout<<index<<endl;
    string minString = s.substr(index);
    reverseString(minString);

    minString += s;

    cout<<minString<<endl;
    return minString;
}
};