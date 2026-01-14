class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        if(n>s.size()) return {};
        unordered_map<char,int> m;
        unordered_map<char,int> m2;
        
        for(int i=0;i<p.size();i++){
            m[p[i]]++;
        }
        vector<int> ans;
        for(int i=0;i<s.size();i++){
            
            m2[s[i]]++;
            
            if(i>p.size()-1){
                char left=s[i-p.size()];
                m2[left]--;
                if(m2[left]==0){
                    m2.erase(left);
                }
                
            }
            
            if(i>=p.size()-1 && m==m2){
                ans.push_back(i-(p.size()-1));
            }
            
        }
        return ans;
    }
};