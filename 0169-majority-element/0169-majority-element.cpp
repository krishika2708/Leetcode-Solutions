class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int element = nums[0];
        int count = 0;
        for (int i = 0; i < n; i++) {
            if(count==0){
                element = nums[i];
                count=1;
                
            }
           else if (nums[i] == element) {
                count++;
            } else {
                count--;
                
            }
        }
        int cnt1=0;
        for (int i = 0; i < n; i++) {
            if(nums[i]==element) cnt1++;
            if (cnt1 > n / 2) {
                return element;
            }
        }
        return -1;
    }
};