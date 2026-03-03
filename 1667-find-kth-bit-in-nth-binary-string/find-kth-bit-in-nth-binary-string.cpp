class Solution {
public:
    string invert(string s){
        for(int i=0; i<s.size(); i++){
            if(s[i] == '0') s[i] = '1';
            else s[i]='0';
            
        }
        return s;
    }
    char findKthBit(int n, int k) {
        string s = "0";
        for(int i=2; i<=n; i++){
            string invs = invert(s);
            reverse(invs.begin(), invs.end());
            string s2 = s + "1" + invs;
            s = s2;
        }
        return s[k-1];
    }
};