class Solution {
public:
    int advance(string& s, int& index, int length)
    {
        if(s[index] == '#')
        {
            index += 2;
            return 0;
        }
        
        for(; index < length & isdigit(s[index]); index ++);
        
        index ++;
        return 1;
    }
    
    bool isValidSerialization(string preorder) {
        int length = preorder.size();
        if(length == 1)
        {
            return preorder[0] == '#';    
        }
        
        stack<char> elements;
        elements.push('#');
        
        int index = 0;
        while(index < length)
        {
            if(elements.empty())
            {
                return false;
            }
            
            elements.pop();
            int value = advance(preorder, index, length);
            
            if(value == 1)
            {
                elements.push('#');
                elements.push('#');
            }
        }
        
        return elements.empty();
    }
};