class Solution {
public:

    unordered_set<string> st;

    void dfs(string &s, int i, int balance,
             int leftRemove, int rightRemove,
             string path) {

        // Invalid
        if(balance < 0)
            return;

        // Too many removals
        if(leftRemove < 0 || rightRemove < 0)
            return;

        // End
        if(i == s.size()) {

            if(balance == 0 &&
               leftRemove == 0 &&
               rightRemove == 0) {

                st.insert(path);
            }

            return;
        }

        // Current character
        char c = s[i];

        // '('
        if(c == '(') {

            // Remove '('
            if(leftRemove > 0) {
                dfs(s, i + 1, balance,
                    leftRemove - 1, rightRemove,
                    path);
            }

            // Keep '('
            dfs(s, i + 1, balance + 1,
                leftRemove, rightRemove,
                path + c);
        }

        // ')'
        else if(c == ')') {

            // Remove ')'
            if(rightRemove > 0) {
                dfs(s, i + 1, balance,
                    leftRemove, rightRemove - 1,
                    path);
            }

            // Keep ')'
            if(balance > 0) {
                dfs(s, i + 1, balance - 1,
                    leftRemove, rightRemove,
                    path + c);
            }
        }

        // Normal character
        else {

            dfs(s, i + 1, balance,
                leftRemove, rightRemove,
                path + c);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for(char c : s) {

            if(c == '(') {

                leftRemove++;

            }
            else if(c == ')') {

                if(leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        dfs(s, 0, 0,
            leftRemove, rightRemove,
            "");

        return vector<string>(st.begin(), st.end());
    }
};