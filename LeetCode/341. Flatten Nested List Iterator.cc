/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
 
typedef pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator> NP;

class NestedIterator {
public:
    stack<NP> nodes;
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        nodes.push(make_pair(nestedList.begin(), nestedList.end()));
    }

    int next() {
        if(hasNext())
        {
            NP top = nodes.top();
            int result = top.first->getInteger();
            nodes.pop();
            top.first ++;
            nodes.push(make_pair(top.first, top.second));
            return result;
        }
        
        return -1;
    }

    bool hasNext() {
        while(nodes.empty() == false)
        {
            NP top = nodes.top();
            
            if(top.first == top.second)
            {
                nodes.pop();
                continue;
            }
            
            if(top.first->isInteger())
            {
                return true;
            }
            
            vector<NestedInteger>& list = top.first->getList();
            nodes.pop();
            top.first ++;
            nodes.push(make_pair(top.first, top.second));
            nodes.push(make_pair(list.begin(), list.end()));
        }
        
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */