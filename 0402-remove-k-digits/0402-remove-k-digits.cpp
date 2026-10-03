class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && k > 0 && num[i] - '0' < st.top()) {
                st.pop();
                k--;
            }
            st.push(num[i] - '0');
        }
        while (k > 0) {
            st.pop();
            k--;
        }
        string result = "";
        if (st.empty())
            return "0";

        while (!st.empty()) {
            result += char(st.top() + '0');
            st.pop();
        }
        reverse(result.begin(), result.end());
        int i = 0;
        while (i < result.size() && result[i] == '0')
            i++;
        result = result.substr(i);
        if (result.empty())
            return "0";

        return result;
    }
};