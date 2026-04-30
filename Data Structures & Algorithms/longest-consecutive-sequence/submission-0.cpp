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
            // Start from current number and find consecutive sequence
            int nextNum = currentNum;

            // Keep incrementing while consecutive numbers exist in the set
            while (numSet.count(nextNum)) {
                // Remove processed number from set to avoid reprocessing
                numSet.erase(nextNum);
                nextNum++;
            }

            // Calculate length of sequence starting from currentNum
            // If nextNum already has a cached sequence length, add it to current calculation
            // Otherwise, just use the difference (nextNum - currentNum)
            int currentSequenceLength = (nextNum - currentNum);
            if (sequenceLengths.count(nextNum)) {
                currentSequenceLength += sequenceLengths[nextNum];
            }

            // Store the sequence length for current starting number
            sequenceLengths[currentNum] = currentSequenceLength;

            // Update maximum length if current sequence is longer
            maxLength = max(maxLength, sequenceLengths[currentNum]);
        }

        return maxLength;
    }
};