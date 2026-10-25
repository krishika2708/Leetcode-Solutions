class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int n = height.size();
        stack<int> st;
        int pse;
        int nse;
        int maxarea = INT_MIN;
        int element;
        int area;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] < height[st.top()]) {
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                area = height[element] * (nse - pse - 1);

                maxarea = max(area, maxarea);
            }
            st.push(i);
        }
        while (!st.empty()) {

            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            area = height[element] * (nse - pse - 1);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }

int maximalRectangle(vector<vector<char>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int maxarea = INT_MIN;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == '1') {
                height[j]++;
            } else
                height[j] = 0;
        }

        maxarea = max(largestRectangleArea(height), maxarea);
    }
    return maxarea;
}
}
;