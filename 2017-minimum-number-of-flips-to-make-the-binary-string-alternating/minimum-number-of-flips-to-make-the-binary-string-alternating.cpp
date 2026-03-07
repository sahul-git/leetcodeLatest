class Solution {
public:

    int minFlips(string s) {
        int n = s.size();
        string str = s + s;

        int odd1 = 0, even1 = 0, odd0 = 0, even0 = 0;

        int minflips = INT_MAX;
        int i = 0;

        for(int right = 0; right < str.size(); right++){

            if(right % 2 == 0){
                if(str[right] == '0') even0++;
                else even1++;
            }else{
                if(str[right] == '0') odd0++;
                else odd1++;
            }

            if(right - i + 1 > n){
                if(i % 2 == 0){
                    if(str[i] == '0') even0--;
                    else even1--;
                }else{
                    if(str[i] == '0') odd0--;
                    else odd1--;
                }
                i++;
            }

            if(right - i + 1 == n){
                int count1 = even1 + odd0;
                int count2 = even0 + odd1;
                minflips = min(minflips, min(count1, count2));
            }
        }

        return minflips;
    }
};