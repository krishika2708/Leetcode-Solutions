class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int pse;
        int nse;
        int maxarea = INT_MIN;
        int element;
        int area;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                element = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                area = heights[element] * (nse - pse - 1);

                maxarea = max(area, maxarea);
            }
            st.push(i);
        }
        while (!st.empty()) {

            nse = n;
            element = st.top();
            st.pop();
            pse = st.empty() ? -1 : st.top();
            area = heights[element] * (nse - pse - 1);
            maxarea = max(area, maxarea);
        }
        return maxarea;
    }
};