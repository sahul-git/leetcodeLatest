class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return true;
        int i= 0 ;
        int j = 1;
        while(j < nums.size()) {
            if(nums[j] != nums[j-1]){
                nums[i+1] = nums[j];
                i++;
            }
            j++;
        }
        return i+1;
    }
};