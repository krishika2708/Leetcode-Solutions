class Solution {
public:
int starting(vector<int>&nums,int target){

int low=0;
int high=nums.size()-1;
int start=-1;
while(low<=high){
    int mid=low+(high-low)/2;
    if(target==nums[mid]){
    start=mid;
        high=mid-1;
    }
    else if(target>nums[mid]){
        low=mid+1;
    }
    else{
        high=mid-1;
    }
   
}
return start;
}
int ending(vector<int>&nums,int target){

int low=0;
int high=nums.size()-1;
int end=-1;
while(low<=high){
    int mid=low+(high-low)/2;
    if(target==nums[mid]){
        end=mid;
         low=mid+1;
    }
    else if(target>nums[mid]){
      low=mid+1;
    }
    else{
        high=mid-1;
    }
   
}
return end;
}
    vector<int> searchRange(vector<int>& nums, int target) {
       int startindex=starting(nums,target);
       int endindex=ending(nums,target);
       return {startindex,endindex};
    }
};