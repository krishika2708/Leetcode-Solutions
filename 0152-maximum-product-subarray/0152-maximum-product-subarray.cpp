class Solution {
public:
    int maxProduct(vector<int>& nums) {

int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < 0)
                swap(maxProd, minProd);

            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            ans = max(ans, maxProd);
        }

        return ans;

    }
};


// brute force
// class Solution {
// public:
//     int maxProduct(vector<int>& nums) {
        
//         int maxi=nums[0];
        
//         for(int i=0;i<nums.size();i++){
//             int p=1;
//                 for(int j=i;j<nums.size();j++){
//                      p=p*nums[j];
//                     maxi=max(maxi,p);
//                 }
//         }
//         return maxi;
        
//     }
// };