class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0)
            return "";
        int maxi = 1;
        int start = 0;
        for (int i = 0; i < n; i++) {
            // even length palindrome
            int l = i;
            int r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxi) {       // length= r-l+1 ;
                    maxi = r - l + 1;
                    start = l;
                }
                l--;
                r++;
                // odd length palindrome
            }

            l = i - 1;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxi) {
                    maxi = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, maxi);
    }
};