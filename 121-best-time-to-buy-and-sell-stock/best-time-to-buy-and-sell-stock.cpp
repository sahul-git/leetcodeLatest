class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxSell = 0;
        int profit = 0;
        for(int i=n-1; i>=0; i--){
            if(prices[i] > maxSell){
                maxSell = prices[i];
            }
            if(i<n-1){
                profit = max(profit, maxSell-prices[i]);
            }
        }
        return profit;
        
    }
};