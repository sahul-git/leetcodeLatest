class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26, 0);

        // count frequency
        for(char t : tasks){
            freq[t - 'A']++;
        }

        sort(freq.begin(), freq.end());

        int maxFreq = freq[25];   // highest frequency
        int countMax = 1;

        // count how many tasks have max frequency
        for(int i = 24; i >= 0; i--){
            if(freq[i] == maxFreq) countMax++;
            else break;
        }

        int ans = (maxFreq - 1) * (n + 1) + countMax;

        return max((int)tasks.size(), ans);
    }
};