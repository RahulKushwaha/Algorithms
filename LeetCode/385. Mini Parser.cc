/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int length = s.size();
        NestedInteger* ns = new NestedInteger();
        if(length == 0)
        {
            return *ns;
        }
        
        string::size_type offset;
        stack<NestedInteger*> nodes;
        nodes.push(ns);
        
        if(s[0] != '[')
        {
            ns->setInteger(stoi(s, &offset));
            return *ns;
        }
        
        int index = 1;
        
        while(index < length)
        {
            if(s[index] == '[')
            {
                NestedInteger* nestedInteger = new NestedInteger();
                nodes.push(nestedInteger);
                index ++;
            }
            else if(s[index] == ']')
            {
                if(index == length - 1)
                {
                    break;
                }
                
                NestedInteger * top = nodes.top();
                nodes.pop();
                nodes.top()->add(*top);
                index ++;
            }
            else if(s[index] == ',')
            {
                index ++;
            }
            else
            {
                int integer = stoi(s.substr(index), &offset);
                NestedInteger ni(integer);
                NestedInteger* top = nodes.top();
                top->add(ni);
                
                index += offset;
            }
        }

        return *ns;
    }
};