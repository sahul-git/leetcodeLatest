class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        vector<int> mp(256,0);
        int maxLen = 0;
        while(right < n){
            mp[s[right]]++;
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;

        }
        return maxLen;
    }
};