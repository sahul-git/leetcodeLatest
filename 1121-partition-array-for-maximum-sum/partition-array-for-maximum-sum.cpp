class Solution {
public:

    int func(vector<int>& arr, int k, int i, int n, vector<int>& dp){
        if(i == n) return 0;
        if(dp[i] != -1) return dp[i];
         int len = 0;
         int maxi = INT_MIN;
         int maxSum = INT_MIN;
         for(int j =i; j<min(i + k, n); j++){
            len ++;
            maxi = max(maxi, arr[j]);
            int sum = (len* maxi)+ func(arr, k, j+1,n, dp );
            maxSum =max(maxSum, sum);
         }
         return dp[i] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return func(arr,k, 0,n, dp);
    }
};