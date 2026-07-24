//optimal approach
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
int cnt1=0;
int cnt2=0;
int ele1=INT_MIN;
int ele2=INT_MIN;
int n=nums.size();

for(int i=0;i<n;i++){       
    if(cnt1==0&& nums[i]!=ele2){
        cnt1=1;
        ele1=nums[i];
    }
    else if(cnt2==0&& nums[i]!=ele1){
        cnt2=1;
        ele2=nums[i];
    }
    else if(nums[i]==ele1){
        cnt1++;
    }
    else if(nums[i]==ele2){
        cnt2++;
    }
    else{
        cnt1--;
        cnt2--;
    }
}
int c1=0;
int c2=0;
vector<int>lst;
for(int i=0;i<nums.size();i++){
    if(ele1==nums[i])c1++;
   if(ele2==nums[i]) { c2++;}
}
int mini=(int)(nums.size()/3)+1;
if(c1>=mini) lst.push_back(ele1);
if(c2>=mini)
lst.push_back(ele2);
sort(lst.begin(),lst.end());
return lst;
    }
};



//better not optimal
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
// vector<int>lst;
//     unordered_map<int,int>mpp;
//     int n=nums.size();
//     int mini=(n/3)+1;
//     for(int i=0;i<nums.size();i++){
//         mpp[nums[i]]++;
    
//     if(mpp[nums[i]]==mini)
//     lst.push_back(nums[i]);
//     if(lst.size()==2){
//         break;
//     }
//     }
//     return lst;
//     }
// };