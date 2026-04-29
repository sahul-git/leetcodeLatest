class Solution {
public:
    int coinNum(int ind, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(ind == 0){
            if(amount == 0){
                return 1;
            }
            if(amount%coins[0] == 0)
                return 1;
            else return 0;
        }
        if(dp[ind][amount]!= -1) return dp[ind][amount];
        int take = 0;
        if(coins[ind]<=amount){
            take =  coinNum(ind, coins, amount-coins[ind], dp);
        }
        int notTake = coinNum(ind-1, coins, amount, dp);

        return dp[ind][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return coinNum(coins.size()-1, coins, amount, dp);
    }
};