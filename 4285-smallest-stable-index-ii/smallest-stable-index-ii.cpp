class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> minArr(n), maxArr(n);
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            maxArr[i] = maxi;
        }

        for(int i=n-1; i>=0; i--){
            mini = min(mini, nums[i]);
            minArr[i] = mini;
        }

        for(int i=0; i<n; i++){
            if(maxArr[i] - minArr[i] <= k) return i;
        }
        return -1;
    }
};