class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr1, arr2;

        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int i = 2;
        int prev1 = arr1[0];
        int prev2 = arr2[0];
        while(i<n){
            if(prev1 > prev2){
                arr1.push_back(nums[i]);
                prev1 = nums[i];
            }else{
                arr2.push_back(nums[i]);
                prev2 = nums[i];
            }
            i++;
        }
        for(int ele : arr2){
            arr1.push_back(ele);
        }
        return arr1;
    }
};