class Solution {
public:
    // int maxGain(int i,int buy, int cap, vector<int>prices, vector<vector<vector<int>>>& dp){
    //     if(cap == 0) return 0;
    //     if(i==prices.size()){
    //         return 0;
    //     }
    //     if(dp[i][buy][cap]!=-1) return dp[i][buy][cap];

    //     int profit = 0;
    //     if(buy){
    //         profit = max(-prices[i]+maxGain(i+1, 0,cap, prices, dp), 0+maxGain(i+1, 1,cap, prices, dp));
    //     }else{
    //         profit = max(prices[i]+maxGain(i+1, 1,cap-1, prices, dp), 0+ maxGain(i+1, 0,cap, prices, dp));
    //     }
    //     return dp[i][buy][cap] = profit;
    // }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        
        for(int i=n-1; i>=0; i--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    int profit = 0;
                    if(buy){
                        profit = max(-prices[i]+dp[i+1][0][cap], 0+dp[i+1][1][cap]);
                    }else{
                        profit = max(prices[i]+dp[i+1][1][cap-1], 0+ dp[i+1][0][cap]);
                    }
                    dp[i][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][k];
    }
};