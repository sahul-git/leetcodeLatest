class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxRight(n);
        vector<int> maxLeft(n);
        int maxi=INT_MIN;
        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, height[i]);
            maxRight[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i=0; i<n; i++){
            maxi = max(maxi, height[i]);
            maxLeft[i] = maxi;
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            int level = min(maxRight[i], maxLeft[i]);
            int water = level - height[i];
            if(water >= 0) ans += water;
        }

        return ans;
    }
};