class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int i=0; 
        int count = 0;
        stack<char> st;
        while(i<n){
            if(s[i] == '('){
                st.push('(');
            }else{
                if(!st.empty() && st.top() == '('){
                    st.pop();
                }else{
                    count++;
                }
            }
            i++;
        }
        count += st.size();
        return count;
    }
};