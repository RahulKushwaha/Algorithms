class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for (int i = 1 ;  ; ++i){
            bool ok = false;
            for (int j = 0 ; !ok && j < nums.size() ; ++j)
                ok |= i == nums[j];
            if (!ok) return i;
        }
    }
};