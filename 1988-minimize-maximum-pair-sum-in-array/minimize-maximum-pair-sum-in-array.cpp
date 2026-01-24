class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size(); 
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = n-1;
        int maxi = 0;
        while(low < high){
            int sum = nums[low] + nums[high];
            maxi = max(maxi, sum);
            low++;
            high--;
        }
        return maxi;
    }
};