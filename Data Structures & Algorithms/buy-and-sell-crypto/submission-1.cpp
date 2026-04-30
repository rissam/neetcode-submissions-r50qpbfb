class Solution {
public:
    int res = 0;
    
    int maxProfit(vector<int>& prices) {
        int min_price  = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            int price = prices[i];
            if(price < min_price) {
                min_price = price;
                continue;
            }
            res = max(res, price - min_price);
        }
        return res;
    }
    
};
