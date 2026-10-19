class Solution {
public:
    int first(vector<int>& arr, int target) {
        int ans = -1;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                high = mid - 1;
            } else if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
    int last(vector<int>& arr, int target) {
        int ans = -1;
        int low = 0;
        int high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                ans = mid;
                low = mid + 1;
            } else if (arr[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return ans;
    }
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int>arr=nums;
        int n = nums.size();
        vector<int> res;
        sort(arr.begin(),arr.end());
        int f = first(arr, target);
        int l = last(arr, target);
        if (f == -1)
            return res;
        for (int i = f; i <= l; i++) {
            res.push_back(i);
        }
        return res;
    }
};
//if you dont take 'arr' and sort original 'nums' array then also there is no problem