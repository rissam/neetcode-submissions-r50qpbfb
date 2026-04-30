class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0;
        unordered_map<char, int> charFreq;
        int left = 0;
        int right;
        int res = 0;
        for(right = 0; right < s.size(); right++) {
            char c = s[right];
            charFreq[c]++;
            maxFreq = max(maxFreq, charFreq[c]);
            while((right-left+1)-maxFreq > k) {
                charFreq[s[left++]]--;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};
