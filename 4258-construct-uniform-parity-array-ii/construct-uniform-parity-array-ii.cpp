class Solution {
public:
    bool canAllEven(vector<int>& nums1, int smallestOdd){
        int n = nums1.size();

        for(int i =0; i<n; i++){
            if(nums1[i] % 2 == 1 && nums1[i]-smallestOdd < 1){
                return false;
            }
        }
        return true;
    }
    bool canAllOdd(vector<int>& nums1, int smallestOdd){
        int n = nums1.size();

        for(int i =0; i<n; i++){
            if(nums1[i] % 2 == 0 && nums1[i]-smallestOdd < 1){
                return false;
            }
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int smallestOdd = INT_MAX;
        int smallestEven = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums1[i] == 1){
                return true;
            }
            if(nums1[i] % 2 == 0) smallestEven = min(smallestEven, nums1[i]);
            else if(nums1[i] % 2 == 1) smallestOdd = min(smallestOdd, nums1[i]);
        }

        return canAllEven(nums1, smallestOdd) || canAllOdd(nums1, smallestOdd);
    }
};