class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> fwdProduct(nums.size(), 1);
        vector<int> revProduct(nums.size(), 1);
        vector<int> result;
        for(int i = 1; i < nums.size(); i++) {
            fwdProduct[i] = nums[i-1]*fwdProduct[i-1]; 
        }
        for(int i = nums.size() -2; i >= 0; i--) {
            revProduct[i] = nums[i+1]*revProduct[i+1]; 
        }
        for(int i = 0; i < nums.size(); i++) {
            result.push_back(fwdProduct[i] * revProduct[i]);
        }
        return result;
    }
};
