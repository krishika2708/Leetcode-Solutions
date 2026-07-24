class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
vector<int>lst;
    unordered_map<int,int>mpp;
    int n=nums.size();
    int mini=(n/3)+1;
    for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
    
    if(mpp[nums[i]]==mini)
    lst.push_back(nums[i]);
    if(lst.size()==2){
        break;
    }
    }
    return lst;
    }
};