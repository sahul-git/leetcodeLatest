class Solution {
public:
    int count1s(int n){
        int ans = 0;
        while(n){
            ans ++;
            n = n & n-1;
        }
        return ans;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++){
            int count = count1s(i);
            ans.push_back(count);
        }
        return ans;
    }
};