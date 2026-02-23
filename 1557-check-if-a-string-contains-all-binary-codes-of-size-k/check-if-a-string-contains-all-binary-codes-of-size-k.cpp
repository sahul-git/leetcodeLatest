
class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (s.size() < k) return false;
        
        unordered_set<string> m;
        string str = s.substr(0, k);
        m.insert(str);
        
        for (int i = k; i < s.size(); i++) {
            str = str.substr(1) + s[i];
            m.insert(str);
        }
        
        return m.size() >= pow(2,k);
    }
};

