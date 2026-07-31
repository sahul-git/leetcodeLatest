class Solution {
public:
    int minimumPushes(string word) {
        
        vector<int> letter(26, 0);
        for(int i=0; i<word.size(); i++){
            letter[word[i] - 'a']++;
        }

        sort(letter.begin(), letter.end(), greater<int>());
        int ans = 0;
        for(int i=0; i<26; i++){
            if(i<8){
                ans += letter[i];
            }else if(i>=8 && i<16){
                ans+= (letter[i] * 2);
            }else if(i>=16 && i< 24){
                ans += (letter[i]*3);
            }else{
                ans += (letter[i]*4);
            }
        }

        return ans;
        
    }
};