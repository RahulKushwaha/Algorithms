class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        ans.push_back(0);
        for (int i = 1 ; i <= num ; ++i){
            // Get the last set bit: (i & -i)
            // We can get the number of bits set in any number less than i
            // As easy operation is to find the number of bits set in a number with the last bit of
            // Number of bits set in the current Number = 1 + (number of bits set in the number with the last bit off[We already know this number as we are storing the results.])
            ans.push_back(1 + ans[(i ^ (i & -i))]);
        }
        return ans;
    }
};