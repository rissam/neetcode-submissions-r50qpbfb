class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result = {};
        if(nums.size() == 0 || k == 0) return result;
        unordered_map<int, int> num_freq;
        unordered_map<int, vector<int>> buckets;
        for(auto &num: nums) {
            num_freq[num]++;
        }
        for(auto &elem: num_freq) {
            buckets[elem.second].push_back(elem.first);
        }
        
        
        for(int i = nums.size(); i > 0; i--) {
            for(int n: buckets[i]) {
                result.push_back(n);
                if(result.size() == k) return result;
            }
        }
        return result;
    }
};
