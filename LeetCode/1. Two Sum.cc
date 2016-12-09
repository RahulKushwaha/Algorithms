class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> numsMap; 
        
        std::vector<int>::iterator it;
        int counter = 0;
        for(it = nums.begin(); it != nums.end(); it ++)
        {
            numsMap[*it] = counter++;
        }
        
        std::vector<int>* result = new std::vector<int>();
        counter = 0;
        for(it = nums.begin(); it != nums.end(); it ++)
        {
            int y = target - *it;
            std::map<int, int>::iterator mapItr = numsMap.find(y);
            if(mapItr != numsMap.end() && counter != mapItr->second)
            {
                result->push_back(counter);
                result->push_back(mapItr->second);
                
                return *result;
            }
            
            counter++;
        }
        
        return *result;
    }
};