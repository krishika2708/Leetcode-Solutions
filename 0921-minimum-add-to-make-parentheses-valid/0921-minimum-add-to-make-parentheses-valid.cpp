class Solution {
public:
    int minAddToMakeValid(string s) {
        int count=0;
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(s[i]);
            else{
                if(!st.empty()&&st.top()=='(')st.pop();
                else{
                    count++;
                }
            }
        }
        return count+st.size();
    }
};