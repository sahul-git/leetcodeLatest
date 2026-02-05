class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, 0);
        for(int i = 0; i<nums.size(); i++){
            int idx = ((i + nums[i]) % n + n) % n;
            result[i] = nums[idx];

        }
        return result;
    }
};