class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int ans=-1;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            int el=nums[i];
            while(el>0){
                sum=sum+(el%10);
                el/=10;
            }
            if(sum==i){
                ans=i;
                break;
            }
        }
        return ans;
    }
};