class Solution {
public:

    int cutting(vector<int>& cuts, int i, int j, vector<vector<int>>& dp){
        if(i+1 == j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini = INT_MAX;
        for(int k = i+1 ; k < j; k++ ){
                int costs =  cuts[j] -cuts[i] + cutting(cuts, i,k, dp)+ cutting(cuts,k,j, dp);
                mini = min(mini, costs);
            


        } 

        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int> (m, -1)); 
        
        
        return cutting(cuts, 0, m-1, dp);



    }
};