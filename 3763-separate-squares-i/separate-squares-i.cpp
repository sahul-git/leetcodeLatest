class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double low = 1e9, high = -1e9;
        double totalArea = 0.0;

        for (auto &s : squares) {
            double y = s[1], side = s[2];
            low = min(low, y);
            high = max(high, y + side);
            totalArea += side * side;
        }

        double half = totalArea / 2.0;

        for (int it = 0; it < 60; it++) {
            double mid = (low + high) / 2.0;
            double below = 0.0;

            for (auto &s : squares) {
                double y = s[1], side = s[2];
                if (mid > y) {
                    below += side * min(side, mid - y);
                }
            }

            if (below < half)
                low = mid;
            else
                high = mid;
        }

        return low;
    }
};
