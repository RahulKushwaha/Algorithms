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
class Solution {
public:
    int getMaxDepth(vector<NestedInteger>& nestedList)
    {
        int length = nestedList.size();
        if(length == 0)
        {
            return 0;
        }
        
        int depth = 1;
        for(int i = 0; i < length; i ++)
        {
            NestedInteger& ns = nestedList[i];
            if(ns.isInteger() == false)
            {
                depth = max(depth, getMaxDepth(ns.getList()) + 1);
            }
        }
        
        return depth;
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        int depth = getMaxDepth(nestedList);
        
        return depthSumInverse(nestedList, depth);
    }
    
    int depthSumInverse(vector<NestedInteger>& nestedList, int depth)
    {
        int currentLevelSum = 0;
        int total = 0;
        int length = nestedList.size();
        if(length == 0)
        {
            return 0;
        }
        
        for(int i = 0; i < length; i ++)
        {
            NestedInteger& ns = nestedList[i];
            if(ns.isInteger())
            {
                currentLevelSum += ns.getInteger();
            }
            else
            {
                total += depthSumInverse(ns.getList(), depth - 1);
            }
        }
        
        return currentLevelSum * depth + total;
    }
};