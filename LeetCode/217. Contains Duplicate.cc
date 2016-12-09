class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        vector<int>::iterator it; 
        set<int> distinctElements;
        
        for(it = nums.begin(); it != nums.end(); it++)
        {
            pair<set<int>::iterator, bool> result = distinctElements.insert(*it);
            if(result.second == false)
            {
                return true;
            }
        }
        
        return false;
    }
};