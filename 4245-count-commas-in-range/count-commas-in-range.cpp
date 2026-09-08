class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        int threshold = 1000;
        
        while (n >= threshold) {
            ans += (n - threshold + 1);
            threshold *= 1000;
        }
        
        return ans;
    }
};