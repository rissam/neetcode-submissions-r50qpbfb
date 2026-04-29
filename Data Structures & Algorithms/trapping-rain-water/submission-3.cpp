class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3) return 0;
        int area = 0;
        int l  = 0;
        int r = height.size()-1;
        int maxLeft = height[l], maxRight = height[r];

        while(l < r) {
            if(maxLeft < maxRight) {
                l++;
                if(height[l] >= maxLeft) {
                    maxLeft = height[l];
                } else {
                    area += maxLeft-height[l];
                }
                
            } else {
                r--;
                if(height[r] >= maxRight) {
                    maxRight = height[r];
                } else {
                    area += maxRight-height[r];
                }
                
            }
        }
        return area;
    }
};
