class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int maxlen = 0;
        vector<int> freq(26, 0);
int maxfreq=0;
        while (r < n) {
            freq[s[r] - 'A']++;
             maxfreq = max(maxfreq, freq[s[r] - 'A']);
            // number of changes required=len - maxfreq
            int numofchanges = (r - l + 1) - maxfreq;
            if (numofchanges > k) {
                freq[s[l] - 'A']--;
               
                l++;
            }
            if (numofchanges <= k) {
                maxlen = max(maxlen, r - l + 1);
            }
            r++;
        }
        return maxlen;
    }
};