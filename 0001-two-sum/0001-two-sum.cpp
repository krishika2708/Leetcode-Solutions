
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         unordered_map<int, int> mp; // value → index

//         for (int i = 0; i < nums.size(); i++) {
//             int complement = target - nums[i];

//             if (mp.find(complement) != mp.end()) {
//                 return {mp[complement], i};
//             }

//             mp[nums[i]] = i;
//         }

//         return {};
//     }
// };



class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
int n=nums.size();
vector<pair<int,int>>numswithindex;

for(int i=0;i<n;i++){
    numswithindex.push_back({nums[i],i});
}
sort(numswithindex.begin(),numswithindex.end());
int left=0;
int right=n-1;
while(left<right){
    int sum=numswithindex[left].first+numswithindex[right].first;
    if(sum==target){
        return{numswithindex[left].second,numswithindex[right].second};
    }
    else if(sum<target){
         left++;
    }
    else{
        right--;
       
    }
}
return{-1,-1};
    }
};    
