class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        deque<int> q; // stores indices

        for (int i = 0; i < n; ++i) {
            // remove out-of-window indices
            while (!q.empty() && q.front() < i - k + 1) q.pop_front();

            // maintain decreasing order in deque
            while (!q.empty() && nums[i] >= nums[q.back()]) q.pop_back();

            q.push_back(i);

            if (i >= k - 1) {
                result.push_back(nums[q.front()]);
            }
        }
        return result;
    }
};