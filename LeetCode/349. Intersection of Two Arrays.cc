class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> elements;
        unordered_set<int> intersection;
        
        for(int i = 0; i < nums1.size(); i ++)
        {
            elements.insert(nums1[i]);
        }
        
        for(int i = 0; i < nums2.size(); i ++)
        {
            unordered_set<int>::iterator itr = elements.find(nums2[i]);
            if(itr != elements.end())
            {
                intersection.insert(nums2[i]);
            }
        }
        
        vector<int> output;
        for(unordered_set<int>::iterator itr = intersection.begin(); itr != intersection.end(); itr ++)
        {
            output.push_back(*itr);
        }
        
        return output;
    }
};