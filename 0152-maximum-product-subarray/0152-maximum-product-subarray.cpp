class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int maxi=nums[0];
        
        for(int i=0;i<nums.size();i++){
            int p=1;
                for(int j=i;j<nums.size();j++){
                     p=p*nums[j];
                    maxi=max(maxi,p);
                }
        }
        return maxi;
        
    }
};