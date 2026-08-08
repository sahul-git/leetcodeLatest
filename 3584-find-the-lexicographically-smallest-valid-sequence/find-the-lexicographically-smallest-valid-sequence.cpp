class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        vector<int> suf(m + 1, n);

        int j = n - 1;

        for (int i = m - 1; i >= 0; i--) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }

            suf[i] = j + 1;
        }

        vector<int> ans;

        int q = 0;
        bool changed = false;

        for (int p = 0; p < m && q < n; p++) {
            if (word1[p] == word2[q]) {
                ans.push_back(p);
                q++;
            }
            else if (!changed) {
                if (suf[p + 1] <= q + 1) {
                    ans.push_back(p);
                    q++;
                    changed = true;
                }
            }
        }

        if (q == n)
            return ans;

        return {};
    }
};