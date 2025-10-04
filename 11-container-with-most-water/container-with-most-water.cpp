class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int max=0;
        while(left<right){
            int water=(right-left)*min(height[left],height[right]);
            if(water>max) max=water;
            if(height[left]<height[right]){ 
                left++;
            }else{
                right--;
            }

        }
        return max;
    }
};