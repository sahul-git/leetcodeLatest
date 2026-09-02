class Solution {
public:
    bool isPalindrome(string s){
        int l = 0;
        int r = s.size()-1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n = s.size();
        int count = 0;
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(s.substr(i, j-i+1))) count++;
            }
        }
        return count;
    }
};