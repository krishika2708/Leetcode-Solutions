class Solution {
public:
 bool ispalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void func(int index, string s,vector<string>& ans,
              vector<vector<string>>& res) {
        if (index == s.size()) {
            res.push_back(ans);
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (ispalindrome(s, index, i)) {
                ans.push_back(s.substr(index, i - index + 1));
                func(i + 1, s, ans, res);
                ans.pop_back();
            }
        }
    }
   
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
       vector<string>ans;
        func(0, s, ans, res);
        return res;
    }
};