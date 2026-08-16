class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        vector<int> m1(256, 0);
        vector<int> m2(256, 0);
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (m1[s[i]] != m2[t[i]]) // yha hm position check rhe dono ki
                return false;
            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }
        return true;
    }
};