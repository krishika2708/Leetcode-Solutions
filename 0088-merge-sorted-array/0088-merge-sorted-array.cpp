// #include<bits/stdc++.h>

// using namespace std;
// class Solution {
//     private:
//     void swapifgreater(vector<int>& nums1, vector<int>& nums2, int ind1, int ind2){
//         if(nums1[ind1]>nums2[ind2]){
//         swap(nums1[ind1],nums2[ind2]);
//         }
//     }
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int len=(m+n);
//         int gap=(len/2)+(len%2);
//         while(gap>0){
//             int left=0;
//             int right=gap+left;
//             while(right<len){
//                     if(left<m&& right>=m){
//                         swapifgreater(nums1,nums2,left,right-m);
//                     }
//                     else if(left>=m){
//                         swapifgreater(nums2,nums2,left-m,right-m);
//                     }
//                     else{
//                         swapifgreater(nums1,nums1,left,right);
//                     }
//                     left++; right++;
//             }
//             if(gap==1){break;}
//             gap=(gap/2)+(gap%2);
//         }
//     }
// };


#include<bits/stdc++.h>

 using namespace std;
 class Solution {
     public:
     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

int left=m-1;
int right=0;
while(left>=0&& right<n){
    if(nums1[left]>nums2[right]){
        swap(nums1[left],nums2[right]);
        left--;
        right++;
    
    }
    else{
        break;
    }
    
}
sort(nums1.begin(),nums1.begin()+m);
sort(nums2.begin(),nums2.begin()+n);
for (int i = 0; i < n; i++) {
    nums1[m + i] = nums2[i];
}
     }
 };
