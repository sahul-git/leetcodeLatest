class Solution {
public:
    int binarySearch(vector<int>& nums,int target, int low, int high){
        while(low <= high){
            int mid = low + (high - low)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] < target) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int pivot = -1;
        while(left < right){
            int mid = left + (right - left)/2;
            if(nums[mid] <=  nums[n-1]){
                right = mid;
            }else{
                left = mid+1;
            }
        }
        pivot = left;
        

        int leftHalf = binarySearch(nums, target, 0, pivot-1);
        int rightHalf = binarySearch(nums, target, pivot, n-1);
        if(leftHalf == -1) return rightHalf;
        else return leftHalf;
        return -1;
    }
};