class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        if(s.size() == 0) return 0;
        int i = s.size()-1;
        int j = g.size()-1;
        while(j>=0 && s[i]<g[j]){
            j--;
        }
        
        int childj = j;
        int count = 0;
        while(childj>=0 && i>=0 ){
            if(g[childj]<= s[i]){
                count++;
                i--;
                childj--;
            }else if(g[childj]>s[i]){
                childj--;
            }
        }
        return count;
    }
};