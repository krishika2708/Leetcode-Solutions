class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int count = 0;
        for (int i = 0; i < s.length(); i++) {

            if (s[i] == ')')
                count--;
            if (count != 0)
                ans.push_back(s[i]);
            if (s[i] == '(')
                count++;
        }
        return ans;
    }
};


// class Solution {
// public:
//     string removeOuterParentheses(string s) {

//         stack<char> st;
//         string ans = "";

//         for(char ch : s)
//         {
//             if(ch == '(')
//             {
//                 if(!st.empty())
//                     ans += ch;

//                 st.push(ch);
//             }
//             else
//             {
//                 st.pop();

//                 if(!st.empty())
//                     ans += ch;
//             }
//         }

//         return ans;
//     }
// };