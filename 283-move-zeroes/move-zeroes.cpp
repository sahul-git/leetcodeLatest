class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n<2 ) return ;
        int i = 0;
        int j = 1;
        
        while(j < n){
            if(nums[j]!=0 && nums[i]==0){
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
            }
            else if( nums[i]!=0 ){
                i++;
            }
            j++;
            
        }
    }
};