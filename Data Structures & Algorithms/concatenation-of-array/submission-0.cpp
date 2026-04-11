class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result;
        for(int iter = 0; iter < 2; iter++) {
        for(int i = 0; i < nums.size(); i++) {
            result.push_back(nums[i]);
        }
        }
        return result;
    }
};