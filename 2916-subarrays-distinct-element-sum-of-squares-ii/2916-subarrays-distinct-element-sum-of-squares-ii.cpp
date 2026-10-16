class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct SegTree {
        int n;
        vector<long long> sum, lazy;

        SegTree(int n) {
            this->n = n;
            sum.resize(4 * n);
            lazy.resize(4 * n);
        }

        void apply(int node, int l, int r) {
            sum[node] += (r - l + 1);
            lazy[node]++;
        }

        void push(int node, int l, int r) {
            if (lazy[node] == 0 || l == r)
                return;

            int mid = (l + r) / 2;

            sum[node * 2] += (mid - l + 1) * lazy[node];
            lazy[node * 2] += lazy[node];

            sum[node * 2 + 1] += (r - mid) * lazy[node];
            lazy[node * 2 + 1] += lazy[node];

            lazy[node] = 0;
        }

        void update(int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l)
                return;

            if (ql <= l && r <= qr) {
                apply(node, l, r);
                return;
            }

            push(node, l, r);

            int mid = (l + r) / 2;

            update(node * 2, l, mid, ql, qr);
            update(node * 2 + 1, mid + 1, r, ql, qr);

            sum[node] = sum[node * 2] + sum[node * 2 + 1];
        }

        void update(int l, int r) {
            if (l <= r)
                update(1, 0, n - 1, l, r);
        }

        long long query(int node, int l, int r, int ql, int qr) {
            if (ql > r || qr < l)
                return 0;

            if (ql <= l && r <= qr)
                return sum[node];

            push(node, l, r);

            int mid = (l + r) / 2;

            return query(node * 2, l, mid, ql, qr) +
                   query(node * 2 + 1, mid + 1, r, ql, qr);
        }

        long long query(int l, int r) {
            if (l > r)
                return 0;

            return query(1, 0, n - 1, l, r);
        }
    };

    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        SegTree st(n);

        unordered_map<int, int> last;

        long long ans = 0;

        long long sum = 0;

        for (int i = 0; i < n; i++) {

            int prev = -1;

            if (last.count(nums[i]))
                prev = last[nums[i]];

            long long affectedSum = st.query(prev + 1, i);

            long long countAffected = i - prev;

            sum = (sum + 2 * affectedSum + countAffected) % MOD;

            st.update(prev + 1, i);

            ans = (ans + sum) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};