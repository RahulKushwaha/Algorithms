class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> output;
        if(nums.size() == 0)
        {
            return output;
        }
        
        //start & end are indices.
        int start = 0;
        int end = 0;
        for(int i = 1;;)
        {
            if(i != nums.size() && nums[i] - nums[i - 1] == 1)
            {
                end = i++;
            }
            else
            {
                string range;
                if(start == end)
                {
                    range = to_string(nums[end]);
                }
                else
                {
                    range = to_string(nums[start]) + "->" + to_string(nums[end]);
                }
                
                output.push_back(range);
                
                start = end = i;

                if(i == nums.size())
                {class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> output; 
        int length = nums.size();
        if(length == 0)
        {
            return output;
        }
        
        unordered_map<int, int> lookup;
        
        for(int i = 0; i < length; i ++)
        {
            unordered_map<int, int>::iterator itr = lookup.find(nums[i]);
            if(itr == lookup.end())
            {
                if(lookup.size() < 3)
                {
                    lookup.insert(pair<int, int>(nums[i], 1));
                }
                else
                {
                    vector<unordered_map<int, int>::iterator> elementsToRemove;
                    for(unordered_map<int, int>::iterator j = lookup.begin(); j != lookup.end(); j ++)
                    {
                        j->second --;
                        if(j->second == 0)
                        {
                            elementsToRemove.push_back(j);
                        }
                    }
                    
                    if(elementsToRemove.size() != 0)
                    {
                        for(int j = 0; j < elementsToRemove.size(); j ++)
                        {
                            lookup.erase(elementsToRemove[j]);
                        }
                        
                        lookup.insert(pair<int, int>(nums[i], 1));
                    }
                }
            }
            else
            {
                itr->second ++ ;
            }
        }
        
        for(unordered_map<int, int>::iterator itr = lookup.begin(); itr != lookup.end(); itr ++)
        {
            int count = 0;
            int num = itr->first;
            
            for(int i = 0; i < length; i ++)
            {
                if(nums[i] == num)
                {
                    count ++;
                }
            }
            
            if(count > length / 3)
            {
                output.push_back(num);
            }
        }
        
        return output;
    }
};
                    break;
                }
                
                i ++;
            }
        }
        
        return output;
    }
};