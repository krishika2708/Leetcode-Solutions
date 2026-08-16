class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0;
        int r = n - 1;
        int area = 0;
        while (l < r) {
            int width = r - l;
            int h = min(height[l], height[r]);
            area = max(area, h * width);
            if (height[l] < height[r]) {
                l++;
            } else
                r--;
        }
        return area;
    }
};