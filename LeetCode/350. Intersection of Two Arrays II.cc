class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> elements;
        
        for(int i = 0; i < nums1.size(); i ++)
        {
            elements[nums1[i]]++;
        }
        
        vector<int> output;
        for(int i = 0; i < nums2.size(); i ++)
        {
            unordered_map<int, int>::iterator itr = elements.find(nums2[i]);
            if(itr != elements.end() && itr->second != 0)
            {
                itr->second --;
                output.push_back(nums2[i]);
            }
        }
        
        return output;
    }
};