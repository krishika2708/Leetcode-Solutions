class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const long long MOD = 1e9 + 7;
        int n = arr.size();
        vector<int> prev(n, -1);
        vector<int>next(n, n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prev[i] = st.top();
            }
            st.push(i);
        }
        while (!st.empty())
            st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            if (!st.empty()) {
                next[i] = st.top();
            }
            st.push(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - prev[i];
            long long right = next[i] - i;
            ans = (ans + (long long)arr[i] * left % MOD * right) % MOD;
        }
        return ans;
    }
};

// TLE

// class Solution {
// public:
//     int sumSubarrayMins(vector<int>& arr) {
//         int n = arr.size();
//         stack<int> st;
//         long long sum = 0;
//         const long long MOD = 1000000007;
//         for (int i = 0; i < n; i++) {
//             while (!st.empty())
//                 st.pop();
//             for (int j = i; j < n; j++) {
//                 if (st.empty())
//                     st.push(arr[j]);
//                 else {
//                     if (st.top() > arr[j]) {
//                         st.pop();
//                         st.push(arr[j]);
//                     }
//                 }
//                 sum = (sum + st.top()) % MOD;
//             }
//         }
//         return sum;
//     }
// };
