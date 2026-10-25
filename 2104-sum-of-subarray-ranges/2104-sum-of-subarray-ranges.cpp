class Solution {
public:
    // psee
    vector<int> PSEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    // nse
    vector<int> NSE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    // pgee
    vector<int> PGEE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : -1;
            st.push(i);
        }
        return ans;
    }
    // nge
    vector<int> NGE(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            ans[i] = !st.empty() ? st.top() : n;
            st.push(i);
        }
        return ans;
    }
    long long subarrayminsum(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> psee = PSEE(nums);
        vector<int> nse = NSE(nums);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            long long freq = left * right;
            long long val = freq * nums[i];
            sum += val;
        }
        return sum;
    }
    long long subarraymaxsum(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> pgee = PGEE(nums);
        vector<int> nge = NGE(nums);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            long long left = i - pgee[i];
            long long right = nge[i] - i;
            long long freq = left * right;
            long long val = freq * nums[i];
            sum += val;
        }
        return sum;
    }

    long long subArrayRanges(vector<int>& nums) {
        return subarraymaxsum(nums) - subarrayminsum(nums);
    }
};