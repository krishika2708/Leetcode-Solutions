class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        vector<int> blocks(101, 0);

        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                blocks[nums[i]]++;
            }
        }

        int count = 0;

        for (int i = 1; i <= 100; i++) {
            if (blocks[i] == 1)
                count++;
        }

        return count;
    }
};