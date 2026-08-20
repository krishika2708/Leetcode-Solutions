class Solution {
public:
    int maxfreq(vector<int>& freq) {
        int maxi = 0;
        for (auto count : freq) {
            maxi = max(maxi, count);
        }
        return maxi;
    }
    int minfreq(vector<int>& freq) {
        int mini = INT_MAX;
        for (auto count : freq) {
            if (count != 0)
                mini = min(mini, count);
        }
        return mini;
    }
    int beautySum(string s) {
        int n = s.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            vector<int>freq(26,0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;
                int beauty = maxfreq(freq) - minfreq(freq);
                sum += beauty;
            }
        }
        return sum;
    }
};