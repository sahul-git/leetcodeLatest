class Solution {
public:
    void lettersComb(int i, string digits, vector<string>& letters, string comb, vector<string>& ans){
        if(i>=digits.size() ){
            ans.push_back(comb);
            return;
        }
        for(int j=0; j<letters[digits[i]-'0'].size(); j++){
            comb.push_back(letters[digits[i]-'0'][j]) ;
            lettersComb(i+1, digits, letters, comb, ans);
            comb.pop_back();
        }


    }
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {
            "","", "abc", "def", "ghi","jkl","mno","pqrs", "tuv", "wxyz"
        };
        vector<string> ans;
        lettersComb(0, digits, letters, "", ans);
        return ans;

    }
};