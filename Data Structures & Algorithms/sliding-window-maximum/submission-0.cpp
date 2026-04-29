class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> output(size-k+1);
        deque<int> dq;
        int l = 0, r = 0;
        while(r< size) {
            while(!dq.empty() && nums[r] > nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(r);
            if(l > dq.front()) dq.pop_front();
            if(r>=k-1) {
                output[l] = nums[dq.front()];
                l++;
            }
            r++;
        }
        return output;
    }
};
