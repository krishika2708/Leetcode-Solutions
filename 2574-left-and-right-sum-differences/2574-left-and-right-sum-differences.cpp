class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {

        int n = nums.size();

        vector<int> left(n);
        vector<int> right(n);
        vector<int> ans(n);

        int leftsum = nums[0];
        left[0] = 0;

        for(int i = 1; i < n; i++){
            left[i] = leftsum;
            leftsum += nums[i];
        }

        int rightsum = nums[n-1];
        right[n-1] = 0;

        for(int i = n-2; i >= 0; i--){
            right[i] = rightsum;
            rightsum += nums[i];
        }

        for(int i = 0; i < n; i++){
            ans[i] = abs(left[i] - right[i]);
        }

        return ans;
    }
};