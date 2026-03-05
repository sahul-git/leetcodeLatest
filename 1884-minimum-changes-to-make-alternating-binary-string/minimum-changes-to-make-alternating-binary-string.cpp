class Solution {
public:
    int minOperations(string s) {
        int odd1 = 0;
        int even1 = 0;
        int odd0 = 0;
        int even0 = 0;
        for(int i=0; i<s.size(); i++){
            if(i % 2 == 0){
                if(s[i]=='0') even0++;
                else even1++;
            }else{
                if(s[i]=='0') odd0++;
                else odd1++;
            }
        }
        
        int count1 = even1 + odd0; // pattern 0101
        int count2 = even0 + odd1; // pattern 1010

       

        int mini = min(count1 , count2);
        return mini;

    }
};