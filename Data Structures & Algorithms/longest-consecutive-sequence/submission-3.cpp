class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // Create a set containing all unique numbers for O(1) lookup
        unordered_set<int> numSet(nums.begin(), nums.end());

        // Track the maximum consecutive sequence length found
        int maxLength = 0;

        // Map to store the length of consecutive sequence starting from each number
        unordered_map<int, int> sequenceLengths;

        // Process each number in the input array
        for (int currentNum : nums) {
            if(sequenceLengths.count(currentNum)) continue;
            // Start from current number and find consecutive sequence
            int nextNum =  currentNum;
            while(numSet.find(nextNum) != numSet.end()) {
                sequenceLengths[currentNum]++;
                numSet.erase(nextNum);
                nextNum++;
            }
            sequenceLengths[currentNum] += sequenceLengths[nextNum];
            maxLength = max(maxLength, sequenceLengths[currentNum]);
        }
        

        return maxLength;
    }
};