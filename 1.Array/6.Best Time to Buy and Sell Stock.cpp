class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int maxProfit = 0;
       
        for(int i=0; i < prices.size(); i++) {
            buy = min(buy, prices[i]);
            // sell = max(sell, prices[i]);
           
            maxProfit = max(maxProfit, prices[i] - buy);
        }
        return maxProfit;
    }
};
