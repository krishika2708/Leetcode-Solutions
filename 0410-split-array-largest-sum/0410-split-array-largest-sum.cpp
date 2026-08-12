class Solution {
public:
bool cansum(vector<int>&nums,int barrier,int k){
    int sum=0;
    int person=1;
    int n=nums.size();
    for(int i=0;i<n;i++){
        if(nums[i]>barrier){
            return false;
        }
        if(sum+nums[i]>barrier){
            person++;
            sum=nums[i];
        }
        else{
            sum+=nums[i];
        }
    }
    if(person>k) return false;
    else return true;
}
int maxi(vector<int>&nums){
    int maxa=INT_MIN;
    for(int i=0;i<nums.size();i++){
        maxa=max(maxa,nums[i]);
    }
    return maxa;
}
int sumation(vector<int>&nums){
    int sumi=0;
    for(int i=0;i<nums.size();i++){
        sumi=sumi+nums[i];
    }
    return sumi;
}
    int splitArray(vector<int>& nums, int k) {
          int low=maxi(nums);
          int high=sumation(nums);
          while(low<=high){
            int mid=low+(high-low)/2;
            if(cansum(nums,mid,k)==true)high=mid-1;
            else  low=mid+1;
          }
          return low;
    }
};