class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0;
        int right = left ;
        int count = 0;
        int minLength = INT_MAX;
        string ans;

        while(right < n){
            if(s[right] == '1'){
                count++;
            }
            while(count == k){
                int len = right - left + 1;
                if(minLength > len){
                    string subs = s.substr(left, len);
                    ans = subs;
                    minLength = len;
                }else if(minLength == len){
                     string subs = s.substr(left, len);
                     if(ans > subs) ans = subs;
                }
                if(s[left] == '1') count--;
                left ++;
                
            }
            right++;
        }
        return ans;
    }
};