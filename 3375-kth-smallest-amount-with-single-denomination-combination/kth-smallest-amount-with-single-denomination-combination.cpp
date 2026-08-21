class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        
        // count of numbers <= x that are multiples of at least one coin
        auto countLE = [&](long long x) -> long long {
            long long total = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long subsetLcm = 1;
                int bits = __builtin_popcount(mask);
                bool overflow = false;
                
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        long long g = __gcd(subsetLcm, (long long)coins[i]);
                        // check overflow before multiplying
                        if (subsetLcm / g > x / coins[i]) {
                            overflow = true;
                            break;
                        }
                        subsetLcm = subsetLcm / g * coins[i];
                        if (subsetLcm > x) {
                            overflow = true;
                            break;
                        }
                    }
                }
                
                if (overflow) continue;
                
                if (bits % 2 == 1) {
                    total += x / subsetLcm;
                } else {
                    total -= x / subsetLcm;
                }
            }
            return total;
        };
        
        long long lo = 1, hi = (long long)(*min_element(coins.begin(), coins.end())) * k;
        
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (countLE(mid) >= k) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        
        return lo;
    }
};