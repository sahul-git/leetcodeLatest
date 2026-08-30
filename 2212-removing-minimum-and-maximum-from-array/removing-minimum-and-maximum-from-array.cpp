class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = -1;

        int minima = INT_MAX;
        int maxima = INT_MIN;

        int maxi = -1;
        for(int i=0; i<n; i++){
            if(nums[i] < minima){
                mini = i;
                minima = nums[i];
            }
            if(nums[i] > maxima){
                maxi = i;
                maxima = nums[i];
            }
            
        }
        int lmin = mini + 1;
        int lmax = maxi + 1;
        int rmin = n - mini;
        int rmax = n - maxi;

        int leftdel = max(lmin, lmax);
        int rightdel = max(rmin, rmax);

        int bothdel = min(lmin, lmax) + min(rmin, rmax);

        if(leftdel <= rightdel && leftdel <= bothdel) return leftdel;
        if(rightdel <= leftdel && rightdel <= bothdel) return rightdel;
        return bothdel;


        
    }
};