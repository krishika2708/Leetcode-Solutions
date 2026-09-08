class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
            int countzeroes=0;
            int len=0;
            int l=0; 
            int r=0;
            int maxlen=0;
            while(r<n){
                if(nums[r]==0) countzeroes++;
                if(countzeroes>k){
                        if(nums[l]==0)  countzeroes--;
                        l++;
                }
                if(countzeroes<=k){
                        len=r-l+1;
                        maxlen=max(maxlen,len);
                }
                r++;
            }
            return maxlen;
    }
};