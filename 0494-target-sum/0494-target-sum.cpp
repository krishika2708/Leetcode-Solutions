class Solution {
public:
int solve(int ind, int sum,vector<int>&nums, int target){
    if(ind==nums.size()){
        if(sum==target) return 1;
        return 0;
    }
    int positive=solve(ind+1,sum+nums[ind],nums,target);
    int negative=solve(ind+1,sum-nums[ind],nums,target);
    return positive+negative;
}
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0,0,nums,target);
    }
};