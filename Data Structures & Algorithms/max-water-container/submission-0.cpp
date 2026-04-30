class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() -1;
        int max_water = 0;
        int area;
        while(l < r) {
           
            if(heights[l] < heights[r]) {
                area =   heights[l] * (r-l);  
                l++;  
            } else {
                area =   heights[r] * (r-l);
                r--;
            }
            
            max_water = max(area, max_water);
        }
        return max_water;
    }
};
