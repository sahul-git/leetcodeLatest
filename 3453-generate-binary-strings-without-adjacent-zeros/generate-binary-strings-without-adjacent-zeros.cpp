class Solution {
public:
    void generate(vector<string>&ans, string str, int i, int n){
        if(i == n){
            ans.push_back(str);
            return;
        }
        if(str.size() == 0 || str.back() == '1' ) generate(ans, str + "0", i+1, n);
        generate(ans, str +"1", i+1, n);
        
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        generate(ans, "", 0, n);
        return ans;
        
    }
};