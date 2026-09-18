class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
         sort(nums.begin(),nums.end());
      int mini=INT_MAX;
      int ans=0;
        for(int i=0;i<nums.size();i++){
            if(i>0&& nums[i]==nums[i-1]) continue;
            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                int sum=nums[i]+nums[left]+nums[right];
                if(sum==target)
                  return sum;
                int complement=abs(target-sum);
                if(complement<mini){
                    mini=complement;
                    ans=sum;
                }
                if(sum<target){
                    left++;
                }
                else{
                    right--;
                }
               
            }
          
        }
    return ans;
    }
};