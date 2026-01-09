class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> sell(n, 0);
        int maxi = 0;
        for(int i = n-1; i>=0; i--){
            sell[i] = maxi;
            maxi = max(maxi, prices[i]);
        }
        int maxProfit = 0;
        for(int i=0; i<n; i++){
            maxProfit = max(maxProfit, sell[i] - prices[i]);
        }
        return maxProfit;
    }
};