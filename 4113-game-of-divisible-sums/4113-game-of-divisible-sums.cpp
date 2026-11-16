class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n=nums.size();
       long long next1=0, next2=0;
        for(int i=n-1;i>=0;i--){
            long long one=nums[i];
            if(one%3==0)one-=next1;
            else one+=next1;
            long long best=one;
            if(i+1<n){
                long long two=nums[i]+nums[i+1];
                if(two%3==0)two-=next2;
                else two+=next2;
                best=max(best,two);
            }
            next2=next1;
            next1=best;
        }
        return next1;
    }
};