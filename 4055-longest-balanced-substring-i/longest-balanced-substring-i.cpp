class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();

        int maxi = 0;

        for(int i=0 ;i<n; i++){
            vector<int> count(26, 0);
            for(int j=i; j<n; j++){
                count[s[j]-'a']++;
                int tar = count[s[j]-'a'];
                bool flag =true;
                for(int k=0; k<=25; k++){
                    if(count[k] > 0 && count[k] != tar){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    maxi = max(maxi, j-i+1);
                }
            }
        }
        return maxi;
    }
};