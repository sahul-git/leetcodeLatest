class Solution {
public:
    int maxGain(int ind, int sell, vector<int>& prices){
        if(ind<0) return 0;
        sell = max(sell, prices[ind]);
        int profit = sell-prices[ind];
        
        profit = max(sell-prices[ind], maxGain(ind-1, sell, prices));
        
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        return maxGain(n-1, 0, prices);
        
    }
};