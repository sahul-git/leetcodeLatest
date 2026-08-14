class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int left = 0;
        int right = 0;
        vector<int> freq(26, 0);
        int maxLen = 0;
        while(right < n){
            int ind = s[right] - 'a';
            freq[ind]++;
            while(freq[ind] > 2){
                int ind2 = s[left] - 'a';
                freq[ind2]--;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;
        }
        return maxLen;
    }
};