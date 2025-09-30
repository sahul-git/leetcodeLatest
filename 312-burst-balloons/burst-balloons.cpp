class Solution {
public:
    int solve(vector<int>& nums, int i, int j, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxi = 0;
        for (int k = i; k <= j; k++) {
            int cost = (nums[i-1] * nums[k] * nums[j+1])
                     + solve(nums, i, k-1, dp)
                     + solve(nums, k+1, j, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;

        arr.push_back(1);
        arr.insert(arr.end(), nums.begin(), nums.end());
        arr.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        return solve(arr, 1, n, dp); 

    }
};
