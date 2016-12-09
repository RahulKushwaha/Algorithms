class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> output;
        
        for(int i = 0; i < strs.size(); i ++)
        {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            output[temp].push_back(strs[i]);
        }

        vector<vector<string>> result ;
        for(unordered_map<string, vector<string>>::iterator itr = output.begin(); itr != output.end(); itr ++)
        {
            result.push_back(itr->second);
        }
        
        return result;
    }
};