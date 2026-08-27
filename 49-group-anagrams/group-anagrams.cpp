class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string, vector<string>> mp;
        // for(int i=0; i<n; i++){
        //     string s = strs[i];
        //     string key = s;
        //     sort(key.begin(), key.end());
        //     mp[key].push_back(s);
        // }
        for(string s : strs){
            vector<int> alpha(26, 0);
            for(char ch : s){
                alpha[ch-'a']++;
            }
            string key;
            for(int i=0; i<26; i++){
                
                while(alpha[i] > 0){
                    key.push_back('a'+ i);
                    alpha[i]--;
                }
                
            }
            mp[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto ele : mp){
            ans.push_back(ele.second);
        }
        return  ans;
    }
};