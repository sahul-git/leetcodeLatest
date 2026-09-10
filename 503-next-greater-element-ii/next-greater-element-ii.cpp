class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int i=0; i<n; i++){
            arr.push_back(nums[i]);
        }
        for(int i=0; i<n; i++){
            arr.push_back(nums[i]);
        }

        stack<int> st;
        vector<int> ans(arr.size());
        for(int i=arr.size()-1; i>=0; i--){
            while(!st.empty() && st.top() <= arr[i]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();
            st.push(arr[i]);
        }
        vector<int> reqAns;
        
        for(int i=0; i<n; i++){
            reqAns.push_back(ans[i]);
        }
        return reqAns;
    }
};