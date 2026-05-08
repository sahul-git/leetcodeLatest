class Solution {
public:
    //  int maxGain(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp){
    //     if(ind == prices.size()) return 0;
    //     if(dp[ind][buy]!= -1) return dp[ind][buy];
        
    //     int profit=INT_MIN;
    //     if(buy){
    //         profit = max(-prices[ind] + maxGain(ind+1, 0, prices, dp), maxGain(ind+1, 1, prices, dp));
    //     }else{
    //         profit = max(prices[ind] + maxGain(ind+1, 1, prices,dp), maxGain(ind+1, 0, prices,dp));
    //     }
    //     return dp[ind][buy] = profit;
    // }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, -1));
        // dp[n][0] = 0;
        // dp[n][1] = 0;
        // for(int i=n-1; i>=0; i--){
            
        //     for(int buy=0; buy<=1; buy++){
        //         int profit = 0;
        //         if(buy) profit = max(-prices[i]+dp[i+1][0], dp[i+1][1]);
        //         else profit = max(prices[i]+dp[i+1][1], dp[i+1][0]);
        //         dp[i][buy] = profit;
        //     }
        // }
        // return dp[0][1];

        vector<int> ahead(2, 0), curr(2,0);

        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                int profit = 0;
                if(buy) profit = max(-prices[i]+ahead[0], ahead[1]);
                else profit = max(prices[i]+ahead[1], ahead[0]);
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];

    }
};