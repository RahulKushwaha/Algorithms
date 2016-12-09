class Solution {
public:
    string removeDuplicateLetters(string s) {
        int length = s.size();
        string output;
        
        if(length == 0)
        {
            return output;
        }
        
        int freq[256] = {0};
        int visited[256] = {0};
        for(int i = 0; i < length; i ++)
        {
            freq[s[i]] ++;
        }
        
        stack<char> elements;
        
        for(int i = 0; i < length; i ++)
        {
            freq[s[i]] --;
            
            if(visited[s[i]])
            {
                continue;
            }
            
            while(elements.empty() == false && elements.top() >= s[i] && freq[elements.top()] > 0)
            {
                visited[elements.top()] = false;
                elements.pop();
            }
            
            visited[s[i]] = true;
            elements.push(s[i]);
        }
        
        stringstream ss;
        
        while(elements.empty() == false)
        {
            ss<<elements.top();
            elements.pop();
        }
        
        output = ss.str();
        reverse(output.begin(), output.end());
        
        return output;
    }
};