class Solution {
public:
    bool isTriangle(int a, int b, int c){
        if(a + b <= c) return false;
        if(a+c <= b)return false;
        if(b+c <= a) return false;

        return true;
    }
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int perimeter = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         for(int k=j+1; k<n; k++){
        //             if(isTriangle( nums[i] , nums[j] , nums[k]))
        //                 perimeter = max(perimeter, nums[i] + nums[j] + nums[k] );
        //         }
        //     }
        // }

        sort(nums.begin(), nums.end());

        for(int i = 0 ;i<n-2; i++){
            int a = nums[i];
            int b = nums[i+1];
            int c = nums[i+2];

            if(isTriangle( a , b,c))
                perimeter= max(perimeter, a+b+c);
        }
        return perimeter;
    }
};