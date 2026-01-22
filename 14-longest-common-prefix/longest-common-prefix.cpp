class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        int n = strs.size();
        string temp = strs[0];
        int mini = INT_MAX;
        for(int i=0; i<strs.size(); i++){
            int count = 0;
            for(int j=0; j<strs[i].size(); j++){
                if(strs[i][j] == temp[j]){
                    count++;
                }else{
                    break;
                }
            }
            mini = min(count, mini);
        }
        return temp.substr(0, mini);
    }
};