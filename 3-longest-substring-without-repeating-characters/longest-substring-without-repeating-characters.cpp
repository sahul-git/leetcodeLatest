class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        unordered_map<int, int> mp;
        int maxLen = 0;
        while(right < n){
            mp[s[right]]++;
            while(mp.size() < right - left + 1){
                mp[s[left]]--;
                if(mp[s[left]] == 0){
                    mp.erase(s[left]);
                }
                left++;
            }
            maxLen = max(maxLen, right-left+1);
            right++;

        }
        return maxLen;
    }
};