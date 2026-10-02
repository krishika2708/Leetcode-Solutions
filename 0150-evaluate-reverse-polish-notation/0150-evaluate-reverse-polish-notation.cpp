class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int>st;
        int ans;
        for (int i = 0; i < n; i++) {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                if(tokens[i]=="+")st.push(t2+t1);
                else if(tokens[i]=="-")st.push(t2-t1);
                else if(tokens[i]=="*")st.push(t2*t1);
                else if(tokens[i]=="/")st.push(t2/t1);
            }
            else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};