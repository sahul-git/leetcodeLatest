class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        int first ;
        int second;

        for(int i= 0 ;i<nums.size(); i++){
            first = nums[i];
            second = target - nums[i];
            if(mp.find(second)!= mp.end()){
                return {i, mp[second]};
            }
            mp[first] = i;
        }
        return {};
    }
};