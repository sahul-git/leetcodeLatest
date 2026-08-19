class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        set<pair<int, int>> st;
        set<int> rows;

        for (auto &seat : reservedSeats) {
            st.insert({seat[0], seat[1]});
            rows.insert(seat[0]);
        }

        // Rows with no reserved seats can fit 2 families
        int ans = (n - rows.size()) * 2;

        for (int row : rows) {

            bool left = true;   // 2,3,4,5
            bool middle = true; // 4,5,6,7
            bool right = true;  // 6,7,8,9

            for (int col = 2; col <= 5; col++) {
                if (st.find({row, col}) != st.end()) {
                    left = false;
                    break;
                }
            }

            for (int col = 4; col <= 7; col++) {
                if (st.find({row, col}) != st.end()) {
                    middle = false;
                    break;
                }
            }

            for (int col = 6; col <= 9; col++) {
                if (st.find({row, col}) != st.end()) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                ans += 2;
            else if (left || middle || right)
                ans++;
        }

        return ans;
    }
};