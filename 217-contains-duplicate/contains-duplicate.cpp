class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_set <int> st;
        for(int ele : nums){
            if(st.find(ele)!= st.end()){
                return true;
            }
            st.insert(ele);
        }
        return false;
    }
};