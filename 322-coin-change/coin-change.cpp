class Solution {
public:
    int coinSolve(int n, vector<int>& coins, int amount, vector<vector<int>>& dp){
        if(n == 0){
            if(amount % coins[0] == 0) return amount / coins[n];
            return 1e9;
        }
        if(dp[n][amount] != -1) return dp[n][amount];
        int take = 1e9;
        if(amount >= coins[n]){
            take = 1 + coinSolve(n, coins, amount-coins[n], dp);
        }
        int notTake = coinSolve(n-1, coins, amount, dp);

        return dp[n][amount] = min(take, notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));

        int ans = coinSolve(n-1, coins, amount, dp);
        if(ans >= 1e9) return -1;
        return ans;

    }
};