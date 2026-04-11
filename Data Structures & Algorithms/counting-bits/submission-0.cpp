class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1, 0);
        int last_pow2 = 0;
        for(int i = 1; i <=n; i++) {
            int curr = i;
            if((curr & (curr-1)) == 0) {
                res[i] = 1;
                last_pow2 = i;
            } else {
                res[i] = 1+ res[i-last_pow2];
            }
        }
        return res;
    }
};
