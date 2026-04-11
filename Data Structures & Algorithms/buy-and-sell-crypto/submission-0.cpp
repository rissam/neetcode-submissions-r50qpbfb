class Solution {
    int max_profit = 0;
    int min_price = INT_MAX;
public:
    int maxProfit(vector<int>& prices) {
        for(auto& price: prices) {
            min_price = min(min_price, price);
            if(price > min_price) {
                max_profit = max(max_profit, price-min_price);
            }
        }
        return max_profit;
    }
};
