class Solution {
public:
    int divisor(vector<int>& nums, int digit) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum+= ceil((double)nums[i] / digit);
            
        }
        return sum;
    }
    
    int maxi(vector<int>& nums) {
        int maximum = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            maximum = max(maximum, nums[i]);
        }
        return maximum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        if(nums.size()>threshold)return -1;
        int low = 1;
        int high = maxi(nums);
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (divisor(nums, mid) <= threshold) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
};