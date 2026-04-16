class Solution {
public:
    // int fibnum(int n, vector<int>& dp){
    //     if(n<=1) return n;
    //     if(dp[n] != -1) return dp[n];

    //     return dp[n] = fibnum(n-1, dp) + fibnum(n-2, dp);
    // }
    // int fib(int n) {
    //     vector<int> dp(n+1, -1);
    //     return fibnum(n, dp);
    // }
    int fib(int n) {
        int prev1 = 1;
        int prev2 = 0;
        int curr = 0;
        if(n == 0) return prev2;
        for(int i=2; i<=n; i++){
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;

    }
};