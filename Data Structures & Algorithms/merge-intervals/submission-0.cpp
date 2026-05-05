class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(auto &interval: intervals) {
            auto &prev_end = result.back()[1];
            int start = interval[0];
            int end = interval[1];
            if(start <= prev_end) {
                result.back()[1] = max(prev_end, end);
            } else {
                result.push_back(interval);
            }
        }
        return result;
    }
};
