class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        
        vector<int> missing(101, -1);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] % k == 0){
                int ind = nums[i]/k;
                missing[ind] = 1;
            }
        }

        for(int i=1; i<=100; i++){
            if(missing[i] == -1) return i*k;
        }
        return 101;

    }
};